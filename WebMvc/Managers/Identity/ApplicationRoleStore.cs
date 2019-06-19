using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Web;
using Microsoft.AspNet.Identity;
using Microsoft.AspNet.Identity.EntityFramework;
using WebMvc.Models.Identity;

namespace WebMvc.Managers.Identity
{
    public class ApplicationRoleStore
        : RoleStore<ApplicationRole, string, ApplicationUserRole>,
            IQueryableRoleStore<ApplicationRole, string>,
            IRoleStore<ApplicationRole, string>, IDisposable
    {
        public ApplicationRoleStore()
            : base(new IdentityDbContext())
        {
            base.DisposeContext = true;
        }

        public ApplicationRoleStore(DbContext context)
            : base(context)
        {
        }
    }
}