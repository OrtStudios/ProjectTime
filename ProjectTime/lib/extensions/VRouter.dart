// ignore_for_file: file_names

import 'package:flutter/material.dart';
import 'package:vrouter/vrouter.dart';


// write an extension on the base widget to make it easier to move between pages
extension EasyRouting on Widget
{
    void goToHomePage(BuildContext context)
    {
        context.vRouter.to("/");
    }

    void goToProjectsLibraryPage(BuildContext context)
    {
        context.vRouter.to("/projects");
    }

    void goto(BuildContext context, String path, {Map<String, String>? params})
    {
        if (params != null)
        {
            context.vRouter.to(path, queryParameters: params);
            return;
        }

        context.vRouter.to(path);
    }

    void gotoNamed(BuildContext context, String name, {
        Map<String, String>? pathParams, Map<String, String>? queryParams
    })
    {
        if (pathParams != null && queryParams != null)
        {
            context.vRouter.toNamed(name, pathParameters: pathParams, queryParameters: queryParams);
            return;
        }

        if (pathParams != null)
        {
            context.vRouter.toNamed(name, pathParameters: pathParams);
            return;
        }

        if (queryParams != null)
        {
            context.vRouter.toNamed(name, queryParameters: queryParams);
            return;
        }

        context.vRouter.toNamed(name);
    }

    void goBack(BuildContext context)
    {
        context.vRouter.pop();
    }
}