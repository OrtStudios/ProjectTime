using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace ProjectTime
{
    public partial class MainWindow : Window
    {
        OORT.OortMain Oort;
        
        private void LoadOort()
        {
            Oort = new OORT.OortMain();
        }

        public MainWindow()
        {
            // Load Oort
            LoadOort();
            Oort!.SetLogLevel(OORT.LogType.DEBUG);
            Oort.Log("Oort Loaded", OORT.LogType.DEBUG);

            // Start the window
            InitializeComponent();
            Oort.Log("App Started", OORT.LogType.INFO);
        }

        protected override void OnClosed(EventArgs e)
        {
            base.OnClosed(e);
            Oort.Log("App Closed", OORT.LogType.INFO);

            if (Oort.IsLogToFile())
            {
                Oort.SaveLogFile();
                Oort.CloseLogFile();
                Oort.DeleteLogFile();
            }

            Oort.Log("Deleting Oort", OORT.LogType.DEBUG);
            Oort?.Dispose();
        }

        private void LogError_Click(object sender, RoutedEventArgs e)
        {
            Oort.Log("Unimplemented Screen Desgin", OORT.LogType.ERROR);
        }
    }
}
