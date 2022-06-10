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
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        Oort.OortMain oort;
        
        private void LoadOort()
        {
            oort = new Oort.OortMain();
        }

        private void EndProgram()
        {
            oort.Dispose();
        }

        public MainWindow()
        {
            LoadOort();
            oort.SetLogLevel(Oort.LogType.LOG_TYPE_INFO);
            
            InitializeComponent();

            oort.Log("Testing", Oort.LogType.LOG_TYPE_INFO);

            EndProgram();
        }
    }
}
