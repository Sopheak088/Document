using System.Linq;
using System.Web.Mvc;
using WebMvc.Models;

namespace WebMvc.Controllers
{
    public class DashboardController : Controller
    {
        public ActionResult Index()
        {
            return View();
        }
    }
}