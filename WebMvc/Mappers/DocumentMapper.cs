using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using WebMvc.Models;
using WebMvc.ViewModels;

namespace WebMvc.Mappers
{
    public static class DocumentMapper
    {
        public static void UpdateDocument(this Document document, DocumentUpdateViewModel documentUpdateViewModel)
        {
            document.Name = documentUpdateViewModel.Name;
            document.Summary = documentUpdateViewModel.Summary;
            document.Tag = documentUpdateViewModel.Tag;
            document.Content = documentUpdateViewModel.Content;
        }

        public static void UpdateDocument(this Document document, DocumentCreateViewModel documentCreateViewModel)
        {
            document.Name = documentCreateViewModel.Name;
            document.Summary = documentCreateViewModel.Summary;
            document.Tag = documentCreateViewModel.Tag;
            document.Content = documentCreateViewModel.Content;
        }
    }
}