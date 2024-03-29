﻿using AutoMapper;
using WebMvc.Models;
using WebMvc.ViewModels;

namespace WebMvc.Mappings
{
    public class AutoMapperConfiguration
    {
        public static void Configure()
        {
            Mapper.Initialize(cfg =>
            {
                cfg.CreateMap<Document, DocumentViewModel>().MaxDepth(2);
                cfg.CreateMap<Document, DocumentCreateViewModel>().MaxDepth(2);
                cfg.CreateMap<Document, DocumentUpdateViewModel>().MaxDepth(2);
            });
        }
    }
}