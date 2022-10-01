using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;



namespace ProjectTime
{
    namespace Core
    {
        internal static class CoreDllPath
        {
            public const string GetCoreDllPath = "C:\\Dev\\ProjectTime\\bin\\Release\\Core\\Core.dll";
        }

        enum LogType
        {
            DEBUG = 0,
            INFO = 1,
            WARNING = 2,
            ERROR = 3,
            FATAL = 4,
            MASTER = 5
        }

        class Logger
        {
            [DllImport(CoreDllPath.GetCoreDllPath)]
            public static extern void LogDebug(string message);

            [DllImport(CoreDllPath.GetCoreDllPath)]
            public static extern void LogInfo(string message);

            [DllImport(CoreDllPath.GetCoreDllPath)]
            public static extern void LogWarning(string message);

            [DllImport(CoreDllPath.GetCoreDllPath)]
            public static extern void LogError(string message);

            [DllImport(CoreDllPath.GetCoreDllPath)]
            public static extern void LogFatal(string message);

            [DllImport(CoreDllPath.GetCoreDllPath)]
            public static extern void LogMaster(string message);

            [DllImport(CoreDllPath.GetCoreDllPath)]
            public static extern void SetLogLevel(LogType logLevel);

        }
    }
}

