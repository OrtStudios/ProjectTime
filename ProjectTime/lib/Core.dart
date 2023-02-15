// ignore_for_file: file_names, camel_case_types

import 'dart:ffi';
import 'package:ffi/ffi.dart';

final coreFunctionsContext = DynamicLibrary.open("assets/Core.dll");

final _logDebug = coreFunctionsContext.lookupFunction<
        Pointer<Utf8> Function(Pointer<Utf8>),
        Pointer<Utf8> Function(Pointer<Utf8>)
    >("LogDebug");

class Core 
{
    static void logDebug(String message) {
        final Pointer<Utf8> messagePtr = message.toNativeUtf8();
        _logDebug(messagePtr);
    }
}