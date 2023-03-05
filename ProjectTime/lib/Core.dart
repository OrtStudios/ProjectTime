// ignore_for_file: file_names, camel_case_types, constant_identifier_names

import 'dart:ffi';
import 'package:ffi/ffi.dart';

final coreFunctionsContext = DynamicLibrary.open("assets/Core.dll");

final _logDebug = coreFunctionsContext.lookupFunction<
        Pointer<Utf8> Function(Pointer<Utf8>),
        Pointer<Utf8> Function(Pointer<Utf8>)
    >("LogDebug");

final _logInfo = coreFunctionsContext.lookupFunction<
        Pointer<Utf8> Function(Pointer<Utf8>),
        Pointer<Utf8> Function(Pointer<Utf8>)
    >("LogInfo");

final _logWarning = coreFunctionsContext.lookupFunction<
        Pointer<Utf8> Function(Pointer<Utf8>),
        Pointer<Utf8> Function(Pointer<Utf8>)
    >("LogWarning");

final _logError = coreFunctionsContext.lookupFunction<
        Pointer<Utf8> Function(Pointer<Utf8>),
        Pointer<Utf8> Function(Pointer<Utf8>)
    >("LogError");

final _logFatal = coreFunctionsContext.lookupFunction<
        Pointer<Utf8> Function(Pointer<Utf8>),
        Pointer<Utf8> Function(Pointer<Utf8>)
    >("LogFatal");

final _logMaster = coreFunctionsContext.lookupFunction<
        Pointer<Utf8> Function(Pointer<Utf8>),
        Pointer<Utf8> Function(Pointer<Utf8>)
    >("LogMaster");

final _setLogLevel = coreFunctionsContext.lookupFunction<
        Pointer<Utf8> Function(Pointer<Utf8>),
        Pointer<Utf8> Function(Pointer<Utf8>)
    >("SetLogLevel");

//extract the LogLevel enum from the C++ code
enum LogLevel 
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    FATAL,
    MASTER 
}

//create a class to wrap the C++ functions
class Core 
{

    static void logDebug(String message) {
        final Pointer<Utf8> messagePtr = message.toNativeUtf8();
        _logDebug(messagePtr);
    }

    static void logInfo(String message) {
        final Pointer<Utf8> messagePtr = message.toNativeUtf8();
        _logInfo(messagePtr);
    }

    static void logWarning(String message) {
        final Pointer<Utf8> messagePtr = message.toNativeUtf8();
        _logWarning(messagePtr);
    }

    static void logError(String message) {
        final Pointer<Utf8> messagePtr = message.toNativeUtf8();
        _logError(messagePtr);
    }

    static void logFatal(String message) {
        final Pointer<Utf8> messagePtr = message.toNativeUtf8();
        _logFatal(messagePtr);
    }

    static void logMaster(String message) {
        final Pointer<Utf8> messagePtr = message.toNativeUtf8();
        _logMaster(messagePtr);
    }

    static void setLogLevel(LogLevel level) {
        final Pointer<Utf8> levelPtr = level.index.toString().toNativeUtf8();
        _setLogLevel(levelPtr);
    }

}