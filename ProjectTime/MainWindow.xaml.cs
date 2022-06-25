﻿using System;
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
        OORT.OortMain Oort;
        
        private void LoadOort()
        {
            Oort = new OORT.OortMain();
        }

        public MainWindow()
        {
            // Load Oort
            LoadOort();
            Oort!.SetLogLevel(OORT.LogType.LOG_TYPE_DEBUG);
            
            // Start the window
            InitializeComponent();
            //Oort.Log("Started App", OORT.LogType.LOG_TYPE_INFO);
        }

        ~MainWindow()
        {
            //Oort.Log("Deleting Oort", OORT.LogType.LOG_TYPE_INFO);
            Oort.Dispose();
        }

        private void LogError_Click(object sender, RoutedEventArgs e)
        {
            Oort.Log("Unimplemented Screen Desgin", OORT.LogType.LOG_TYPE_ERROR);
        }
    }
}
