using Microsoft.AspNet.Identity;
using Microsoft.AspNet.Identity.EntityFramework;
using WebMvc.Models;
using WebMvc.Models.Identity;

namespace WebMvc.Migrations
{
    using System;
    using System.Data.Entity;
    using System.Data.Entity.Migrations;
    using System.Linq;

    internal sealed class Configuration : DbMigrationsConfiguration<WebMvc.Models.ApplicationDbContext>
    {
        public Configuration()
        {
            AutomaticMigrationsEnabled = false;
        }

        protected override void Seed(WebMvc.Models.ApplicationDbContext context)
        {
            //  This method will be called after migrating to the latest version.

            //  You can use the DbSet<T>.AddOrUpdate() helper extension method 
            //  to avoid creating duplicate seed data. E.g.
            //
            //    context.People.AddOrUpdate(
            //      p => p.FullName,
            //      new Person { FullName = "Andrew Peters" },
            //      new Person { FullName = "Brice Lambson" },
            //      new Person { FullName = "Rowan Miller" }
            //    );
            //
            AddUser(context);
        }
        private async void AddUser(ApplicationDbContext context)
        {
            if (!context.Users.Any())
            {
                var manager = new UserManager<ApplicationUser, string>(new UserStore<ApplicationUser, ApplicationRole, string, ApplicationUserLogin, ApplicationUserRole, ApplicationUserClaim>(new ApplicationDbContext()));

                var roleManager = new RoleManager<ApplicationRole, string>(new RoleStore<ApplicationRole, string, ApplicationUserRole>(new ApplicationDbContext()));

                var user = new ApplicationUser()
                {
                    UserName = "admin",
                    Email = "huynhquy9x@gmail.com",
                    EmailConfirmed = true,
                    PhoneNumber = "0976656454",
                    PhoneNumberConfirmed = true
                };

                manager.Create(user, "Bidc@123");

                if (!roleManager.Roles.Any(m => m.Name == "Admin"))
                {
                    await roleManager.CreateAsync(new ApplicationRole("Admin"));
                }

                var adminUser = manager.FindByEmail("huynhquy9x@gmail.com");

                manager.AddToRoles(adminUser.Id, new string[] { "Admin" });
            }
        }
    }
}
