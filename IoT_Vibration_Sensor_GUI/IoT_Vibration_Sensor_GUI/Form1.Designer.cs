namespace IoT_Vibration_Sensor_GUI
{
    partial class IoTVibrationSensorGUI
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend1 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series1 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Title title1 = new System.Windows.Forms.DataVisualization.Charting.Title();
            this.VSMmenuStrip = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutVibrationSensorMonitorToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.infoPanel = new System.Windows.Forms.Panel();
            this.infoTableLayoutPanel = new System.Windows.Forms.TableLayoutPanel();
            this.xAxisGroupBox = new System.Windows.Forms.GroupBox();
            this.xAxisGraphChart = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.graphTestButton = new System.Windows.Forms.Button();
            this.xPointsGroupBox = new System.Windows.Forms.GroupBox();
            this.xPointsTextBox = new System.Windows.Forms.TextBox();
            this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.VSMmenuStrip.SuspendLayout();
            this.infoPanel.SuspendLayout();
            this.infoTableLayoutPanel.SuspendLayout();
            this.xAxisGroupBox.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.xAxisGraphChart)).BeginInit();
            this.xPointsGroupBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // VSMmenuStrip
            // 
            this.VSMmenuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.helpToolStripMenuItem});
            this.VSMmenuStrip.Location = new System.Drawing.Point(0, 0);
            this.VSMmenuStrip.Name = "VSMmenuStrip";
            this.VSMmenuStrip.Size = new System.Drawing.Size(984, 24);
            this.VSMmenuStrip.TabIndex = 0;
            this.VSMmenuStrip.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.saveToolStripMenuItem,
            this.toolStripSeparator1,
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "&File";
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(149, 6);
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.exitToolStripMenuItem.Text = "E&xit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.aboutVibrationSensorMonitorToolStripMenuItem});
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.helpToolStripMenuItem.Text = "&Help";
            // 
            // aboutVibrationSensorMonitorToolStripMenuItem
            // 
            this.aboutVibrationSensorMonitorToolStripMenuItem.Name = "aboutVibrationSensorMonitorToolStripMenuItem";
            this.aboutVibrationSensorMonitorToolStripMenuItem.Size = new System.Drawing.Size(242, 22);
            this.aboutVibrationSensorMonitorToolStripMenuItem.Text = "About Vibration Sensor Monitor";
            this.aboutVibrationSensorMonitorToolStripMenuItem.Click += new System.EventHandler(this.aboutVibrationSensorMonitorToolStripMenuItem_Click);
            // 
            // infoPanel
            // 
            this.infoPanel.Controls.Add(this.infoTableLayoutPanel);
            this.infoPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.infoPanel.Location = new System.Drawing.Point(0, 24);
            this.infoPanel.Name = "infoPanel";
            this.infoPanel.Size = new System.Drawing.Size(984, 338);
            this.infoPanel.TabIndex = 1;
            // 
            // infoTableLayoutPanel
            // 
            this.infoTableLayoutPanel.ColumnCount = 3;
            this.infoTableLayoutPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 84.06828F));
            this.infoTableLayoutPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 15.93172F));
            this.infoTableLayoutPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 80F));
            this.infoTableLayoutPanel.Controls.Add(this.xAxisGroupBox, 0, 0);
            this.infoTableLayoutPanel.Controls.Add(this.graphTestButton, 2, 0);
            this.infoTableLayoutPanel.Controls.Add(this.xPointsGroupBox, 1, 0);
            this.infoTableLayoutPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.infoTableLayoutPanel.Location = new System.Drawing.Point(0, 0);
            this.infoTableLayoutPanel.Name = "infoTableLayoutPanel";
            this.infoTableLayoutPanel.RowCount = 1;
            this.infoTableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.infoTableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.infoTableLayoutPanel.Size = new System.Drawing.Size(984, 338);
            this.infoTableLayoutPanel.TabIndex = 0;
            // 
            // xAxisGroupBox
            // 
            this.xAxisGroupBox.Controls.Add(this.xAxisGraphChart);
            this.xAxisGroupBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.xAxisGroupBox.Location = new System.Drawing.Point(3, 3);
            this.xAxisGroupBox.Name = "xAxisGroupBox";
            this.xAxisGroupBox.Size = new System.Drawing.Size(753, 332);
            this.xAxisGroupBox.TabIndex = 0;
            this.xAxisGroupBox.TabStop = false;
            this.xAxisGroupBox.Text = "X-Axis";
            // 
            // xAxisGraphChart
            // 
            this.xAxisGraphChart.BackColor = System.Drawing.Color.Transparent;
            chartArea1.AxisX.IsMarginVisible = false;
            chartArea1.AxisX.Title = "Frequency (Hz)";
            chartArea1.AxisX.TitleFont = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            chartArea1.AxisY.Title = "Relative Amp (Amps)";
            chartArea1.AxisY.TitleFont = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            chartArea1.BackColor = System.Drawing.Color.Transparent;
            chartArea1.BackSecondaryColor = System.Drawing.Color.White;
            chartArea1.Name = "ChartArea1";
            this.xAxisGraphChart.ChartAreas.Add(chartArea1);
            this.xAxisGraphChart.Dock = System.Windows.Forms.DockStyle.Fill;
            legend1.Name = "Legend1";
            this.xAxisGraphChart.Legends.Add(legend1);
            this.xAxisGraphChart.Location = new System.Drawing.Point(3, 16);
            this.xAxisGraphChart.Name = "xAxisGraphChart";
            series1.BorderWidth = 2;
            series1.ChartArea = "ChartArea1";
            series1.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series1.Legend = "Legend1";
            series1.Name = "graphTest";
            this.xAxisGraphChart.Series.Add(series1);
            this.xAxisGraphChart.Size = new System.Drawing.Size(747, 313);
            this.xAxisGraphChart.TabIndex = 0;
            this.xAxisGraphChart.Text = "X-Axis";
            title1.Alignment = System.Drawing.ContentAlignment.TopCenter;
            title1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            title1.Name = "graphTestTitle";
            title1.Text = "X-Axis";
            this.xAxisGraphChart.Titles.Add(title1);
            // 
            // graphTestButton
            // 
            this.graphTestButton.Location = new System.Drawing.Point(906, 3);
            this.graphTestButton.Name = "graphTestButton";
            this.graphTestButton.Size = new System.Drawing.Size(75, 23);
            this.graphTestButton.TabIndex = 1;
            this.graphTestButton.Text = "Graph Test";
            this.graphTestButton.UseVisualStyleBackColor = true;
            this.graphTestButton.Click += new System.EventHandler(this.graphTestButton_Click);
            // 
            // xPointsGroupBox
            // 
            this.xPointsGroupBox.Controls.Add(this.xPointsTextBox);
            this.xPointsGroupBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.xPointsGroupBox.Location = new System.Drawing.Point(762, 3);
            this.xPointsGroupBox.Name = "xPointsGroupBox";
            this.xPointsGroupBox.Size = new System.Drawing.Size(138, 332);
            this.xPointsGroupBox.TabIndex = 2;
            this.xPointsGroupBox.TabStop = false;
            this.xPointsGroupBox.Text = "Points";
            // 
            // xPointsTextBox
            // 
            this.xPointsTextBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.xPointsTextBox.Location = new System.Drawing.Point(3, 16);
            this.xPointsTextBox.Multiline = true;
            this.xPointsTextBox.Name = "xPointsTextBox";
            this.xPointsTextBox.ReadOnly = true;
            this.xPointsTextBox.Size = new System.Drawing.Size(132, 313);
            this.xPointsTextBox.TabIndex = 0;
            // 
            // saveToolStripMenuItem
            // 
            this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
            this.saveToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.saveToolStripMenuItem.Text = "Save";
            this.saveToolStripMenuItem.Click += new System.EventHandler(this.saveToolStripMenuItem_Click);
            // 
            // IoTVibrationSensorGUI
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(984, 362);
            this.Controls.Add(this.infoPanel);
            this.Controls.Add(this.VSMmenuStrip);
            this.MainMenuStrip = this.VSMmenuStrip;
            this.Name = "IoTVibrationSensorGUI";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Vibration Sensor Monitor";
            this.VSMmenuStrip.ResumeLayout(false);
            this.VSMmenuStrip.PerformLayout();
            this.infoPanel.ResumeLayout(false);
            this.infoTableLayoutPanel.ResumeLayout(false);
            this.xAxisGroupBox.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.xAxisGraphChart)).EndInit();
            this.xPointsGroupBox.ResumeLayout(false);
            this.xPointsGroupBox.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip VSMmenuStrip;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutVibrationSensorMonitorToolStripMenuItem;
        private System.Windows.Forms.Panel infoPanel;
        private System.Windows.Forms.TableLayoutPanel infoTableLayoutPanel;
        private System.Windows.Forms.GroupBox xAxisGroupBox;
        private System.Windows.Forms.DataVisualization.Charting.Chart xAxisGraphChart;
        private System.Windows.Forms.Button graphTestButton;
        private System.Windows.Forms.GroupBox xPointsGroupBox;
        private System.Windows.Forms.TextBox xPointsTextBox;
        private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
    }
}

