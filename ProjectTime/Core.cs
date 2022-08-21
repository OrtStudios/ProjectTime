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
            
        }
    }
}

