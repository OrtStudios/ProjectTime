// ignore_for_file: file_names, non_constant_identifier_names, library_prefixes

import 'package:flutter/material.dart';

// Other
import 'package:project_time/main.config.dart' as ptConfig;

int GetPageIndex(Widget page)
{
    // get page name:
    String pageName = page.toString();
    pageName = pageName.replaceAll("Page", "");

    // get page number:
    String pageCategory = ptConfig.PagesByCategories[pageName] ?? "Home";
    int pageNumber = ptConfig.PagesCategories[pageCategory] ?? 0;

    return pageNumber;
}