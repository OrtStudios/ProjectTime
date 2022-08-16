using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace ProjectTime
{
    internal class Core
    {
        const string CoreDllPath = "C:\\Dev\\ProjectTime\\bin\\Release\\Core\\Core.dll";

        [DllImport(CoreDllPath)]
        public static extern void LogTest(string message);
    }
}
