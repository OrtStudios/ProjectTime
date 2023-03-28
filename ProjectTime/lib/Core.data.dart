// ignore_for_file: file_names, camel_case_types, constant_identifier_names

import 'dart:ffi';

final coreFunctionsContext = DynamicLibrary.open("assets/Core.dll");

class Core {}