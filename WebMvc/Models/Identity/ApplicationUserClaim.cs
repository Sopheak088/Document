﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using Microsoft.AspNet.Identity.EntityFramework;

namespace WebMvc.Models.Identity
{
    public class ApplicationUserClaim : IdentityUserClaim<string> { }
}