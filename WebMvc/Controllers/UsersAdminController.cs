﻿using Microsoft.AspNet.Identity.Owin;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Threading.Tasks;
using System.Web;
using System.Web.Mvc;
using WebMvc.Managers.Identity;
using WebMvc.Models;
using WebMvc.Models.Identity;
using WebMvc.ViewModels;

namespace WebMvc.Controllers
{
    [Authorize]
    public class UsersAdminController : Controller
    {
        public UsersAdminController()
        {
        }

        private ApplicationDbContext db = new ApplicationDbContext();

        public UsersAdminController(ApplicationUserManager userManager,
            ApplicationRoleManager roleManager)
        {
            UserManager = userManager;
            RoleManager = roleManager;
        }

        private ApplicationUserManager _userManager;

        public ApplicationUserManager UserManager
        {
            get
            {
                return _userManager ?? HttpContext.GetOwinContext()
                    .GetUserManager<ApplicationUserManager>();
            }
            private set
            {
                _userManager = value;
            }
        }

        // Add the Group Manager (NOTE: only access through the public
        // Property, not by the instance variable!)
        private ApplicationGroupManager _groupManager;

        public ApplicationGroupManager GroupManager
        {
            get
            {
                return _groupManager ?? new ApplicationGroupManager();
            }
            private set
            {
                _groupManager = value;
            }
        }

        private ApplicationRoleManager _roleManager;

        public ApplicationRoleManager RoleManager
        {
            get
            {
                return _roleManager ?? HttpContext.GetOwinContext()
                    .Get<ApplicationRoleManager>();
            }
            private set
            {
                _roleManager = value;
            }
        }

        public ActionResult Index(string search)
        {
            var user = UserManager.Users;
            if (!string.IsNullOrWhiteSpace(search))
            {
                user = UserManager.Users.Where(s => s.UserName.Contains(search));
            }

            return View(user);
        }

        public async Task<ActionResult> Details(string id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            var user = await UserManager.FindByIdAsync(id);

            // Show the groups the user belongs to:
            var userGroups = await this.GroupManager.GetUserGroupsAsync(id);
            ViewBag.GroupNames = userGroups.Select(u => u.Name).ToList();
            return View(user);
        }

        [Authorize(Roles = "Admin, UsersAdminCreate")]
        public ActionResult Create()
        {
            // Show a list of available groups:
            ViewBag.GroupsList =
                new SelectList(this.GroupManager.Groups, "Id", "Name");
            return View();
        }

        [HttpPost]
        //[Authorize(Roles = "Admin, UsersAdminCreate")]
        public async Task<ActionResult> Create(RegisterViewModel userViewModel,
            params string[] selectedGroups)
        {
            if (ModelState.IsValid)
            {
                var user = new ApplicationUser
                {
                    UserName = userViewModel.Email,
                    Email = userViewModel.Email
                };
                var adminresult = await UserManager
                    .CreateAsync(user, userViewModel.Password);

                //Add User to the selected Groups
                if (adminresult.Succeeded)
                {
                    if (selectedGroups != null)
                    {
                        selectedGroups = selectedGroups ?? new string[] { };
                        await this.GroupManager
                            .SetUserGroupsAsync(user.Id, selectedGroups);
                    }
                    return RedirectToAction("Index");
                }
            }
            ViewBag.Groups = new SelectList(await RoleManager.Roles.ToListAsync(), "Id", "Name");
            ViewBag.GroupsList = new SelectList(this.GroupManager.Groups, "Id", "Name");
            //ViewBag.Groups = new SelectList(, "Id", "Name");
            return View();
        }

        [Authorize(Roles = "Admin, UsersAdminEditor")]
        public async Task<ActionResult> Edit(string id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            var user = await UserManager.FindByIdAsync(id);
            if (user == null)
            {
                return HttpNotFound();
            }

            // Display a list of available Groups:
            var allGroups = this.GroupManager.Groups;
            var userGroups = await this.GroupManager.GetUserGroupsAsync(id);

            var model = new EditUserViewModel()
            {
                Id = user.Id,
                Email = user.Email
            };

            foreach (var group in allGroups)
            {
                var listItem = new SelectListItem()
                {
                    Text = group.Name,
                    Value = group.Id,
                    Selected = userGroups.Any(g => g.Id == group.Id)
                };
                model.GroupsList.Add(listItem);
            }
            return View(model);
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        [Authorize(Roles = "Admin, UsersAdminEditor")]
        public async Task<ActionResult> Edit(
            [Bind(Include = "Email,Id")] EditUserViewModel editUser,
            params string[] selectedGroups)
        {
            if (ModelState.IsValid)
            {
                var user = await UserManager.FindByIdAsync(editUser.Id);
                if (user == null)
                {
                    return HttpNotFound();
                }

                // Update the User:
                user.UserName = editUser.Email;
                user.Email = editUser.Email;
                await this.UserManager.UpdateAsync(user);

                // Update the Groups:
                selectedGroups = selectedGroups ?? new string[] { };
                await this.GroupManager.SetUserGroupsAsync(user.Id, selectedGroups);
                return RedirectToAction("Index");
            }
            ModelState.AddModelError("", "Something failed.");
            return View();
        }

        [Authorize(Roles = "Admin, UsersAdminDelete")]
        public async Task<ActionResult> Delete(string id)
        {
            if (ModelState.IsValid)
            {
                if (id == null)
                {
                    return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
                }

                var user = await UserManager.FindByIdAsync(id);
                if (user == null)
                {
                    return HttpNotFound();
                }

                // Remove all the User Group references:
                await this.GroupManager.ClearUserGroupsAsync(id);

                // Then Delete the User:
                var result = await UserManager.DeleteAsync(user);
                if (!result.Succeeded)
                {
                    ModelState.AddModelError("", result.Errors.First());
                    return View();
                }
                return RedirectToAction("Index");
            }
            return View();
        }
    }
}