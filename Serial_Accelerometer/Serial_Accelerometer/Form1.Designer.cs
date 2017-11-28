namespace Serial_Accelerometer
{
    partial class Form1
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
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea2 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend2 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series4 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Series series5 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Series series6 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.PanelButtons = new System.Windows.Forms.Panel();
            this.TextBoxPortStatus = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.ButtonClose = new System.Windows.Forms.Button();
            this.ButtonOpen = new System.Windows.Forms.Button();
            this.ComboComBox = new System.Windows.Forms.ComboBox();
            this.PanelChart = new System.Windows.Forms.Panel();
            this.ChartSerialPlot = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.TimerUpdate = new System.Windows.Forms.Timer(this.components);
            this.ButtonClear = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.PanelButtons.SuspendLayout();
            this.PanelChart.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ChartSerialPlot)).BeginInit();
            this.SuspendLayout();
            // 
            // PanelButtons
            // 
            this.PanelButtons.Controls.Add(this.label1);
            this.PanelButtons.Controls.Add(this.ButtonClear);
            this.PanelButtons.Controls.Add(this.TextBoxPortStatus);
            this.PanelButtons.Controls.Add(this.label2);
            this.PanelButtons.Controls.Add(this.ButtonClose);
            this.PanelButtons.Controls.Add(this.ButtonOpen);
            this.PanelButtons.Controls.Add(this.ComboComBox);
            this.PanelButtons.Location = new System.Drawing.Point(1, 0);
            this.PanelButtons.Name = "PanelButtons";
            this.PanelButtons.Size = new System.Drawing.Size(170, 287);
            this.PanelButtons.TabIndex = 0;
            // 
            // TextBoxPortStatus
            // 
            this.TextBoxPortStatus.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.TextBoxPortStatus.Location = new System.Drawing.Point(17, 94);
            this.TextBoxPortStatus.Name = "TextBoxPortStatus";
            this.TextBoxPortStatus.ReadOnly = true;
            this.TextBoxPortStatus.Size = new System.Drawing.Size(142, 22);
            this.TextBoxPortStatus.TabIndex = 9;
            // 
            // label2
            // 
            this.label2.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.Color.SlateGray;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.Color.White;
            this.label2.Location = new System.Drawing.Point(44, 74);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(89, 17);
            this.label2.TabIndex = 10;
            this.label2.Text = "Port Status";
            // 
            // ButtonClose
            // 
            this.ButtonClose.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.ButtonClose.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.ButtonClose.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ButtonClose.ForeColor = System.Drawing.Color.White;
            this.ButtonClose.Location = new System.Drawing.Point(17, 188);
            this.ButtonClose.Name = "ButtonClose";
            this.ButtonClose.Size = new System.Drawing.Size(142, 36);
            this.ButtonClose.TabIndex = 7;
            this.ButtonClose.Text = "Close Port";
            this.ButtonClose.UseVisualStyleBackColor = true;
            this.ButtonClose.Click += new System.EventHandler(this.ButtonClose_Click);
            // 
            // ButtonOpen
            // 
            this.ButtonOpen.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.ButtonOpen.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.ButtonOpen.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.ButtonOpen.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ButtonOpen.ForeColor = System.Drawing.Color.White;
            this.ButtonOpen.Location = new System.Drawing.Point(17, 140);
            this.ButtonOpen.Name = "ButtonOpen";
            this.ButtonOpen.Size = new System.Drawing.Size(142, 36);
            this.ButtonOpen.TabIndex = 6;
            this.ButtonOpen.Text = "Open Port";
            this.ButtonOpen.UseVisualStyleBackColor = true;
            this.ButtonOpen.Click += new System.EventHandler(this.ButtonOpen_Click);
            // 
            // ComboComBox
            // 
            this.ComboComBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.ComboComBox.FormattingEnabled = true;
            this.ComboComBox.Location = new System.Drawing.Point(17, 36);
            this.ComboComBox.Name = "ComboComBox";
            this.ComboComBox.Size = new System.Drawing.Size(142, 24);
            this.ComboComBox.TabIndex = 3;
            // 
            // PanelChart
            // 
            this.PanelChart.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.PanelChart.Controls.Add(this.ChartSerialPlot);
            this.PanelChart.Location = new System.Drawing.Point(172, 0);
            this.PanelChart.Name = "PanelChart";
            this.PanelChart.Size = new System.Drawing.Size(888, 537);
            this.PanelChart.TabIndex = 1;
            // 
            // ChartSerialPlot
            // 
            this.ChartSerialPlot.BackColor = System.Drawing.Color.DimGray;
            chartArea2.AxisX.LabelStyle.ForeColor = System.Drawing.Color.White;
            chartArea2.AxisX.LineColor = System.Drawing.Color.White;
            chartArea2.AxisX.MajorGrid.LineColor = System.Drawing.Color.White;
            chartArea2.AxisX.MajorTickMark.LineColor = System.Drawing.Color.White;
            chartArea2.AxisX.MinorGrid.LineColor = System.Drawing.Color.White;
            chartArea2.AxisX.MinorTickMark.LineColor = System.Drawing.Color.White;
            chartArea2.AxisX.Title = "Time (ms)";
            chartArea2.AxisX.TitleFont = new System.Drawing.Font("Microsoft Sans Serif", 16F);
            chartArea2.AxisX.TitleForeColor = System.Drawing.Color.White;
            chartArea2.AxisY.LabelStyle.ForeColor = System.Drawing.Color.White;
            chartArea2.AxisY.LineColor = System.Drawing.Color.White;
            chartArea2.AxisY.MajorGrid.LineColor = System.Drawing.Color.White;
            chartArea2.AxisY.MajorTickMark.LineColor = System.Drawing.Color.White;
            chartArea2.AxisY.MinorGrid.LineColor = System.Drawing.Color.White;
            chartArea2.AxisY.MinorTickMark.LineColor = System.Drawing.Color.White;
            chartArea2.AxisY.Title = "Acceleration (mg)";
            chartArea2.AxisY.TitleFont = new System.Drawing.Font("Microsoft Sans Serif", 16F);
            chartArea2.AxisY.TitleForeColor = System.Drawing.Color.White;
            chartArea2.BackColor = System.Drawing.SystemColors.ControlText;
            chartArea2.Name = "ChartArea1";
            this.ChartSerialPlot.ChartAreas.Add(chartArea2);
            this.ChartSerialPlot.Dock = System.Windows.Forms.DockStyle.Fill;
            legend2.BackColor = System.Drawing.Color.DimGray;
            legend2.DockedToChartArea = "ChartArea1";
            legend2.ForeColor = System.Drawing.Color.White;
            legend2.Name = "Legend1";
            this.ChartSerialPlot.Legends.Add(legend2);
            this.ChartSerialPlot.Location = new System.Drawing.Point(0, 0);
            this.ChartSerialPlot.Name = "ChartSerialPlot";
            series4.ChartArea = "ChartArea1";
            series4.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Spline;
            series4.Legend = "Legend1";
            series4.Name = "X_DATA";
            series5.ChartArea = "ChartArea1";
            series5.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Spline;
            series5.Legend = "Legend1";
            series5.Name = "Y_DATA";
            series6.ChartArea = "ChartArea1";
            series6.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Spline;
            series6.Legend = "Legend1";
            series6.Name = "Z_DATA";
            this.ChartSerialPlot.Series.Add(series4);
            this.ChartSerialPlot.Series.Add(series5);
            this.ChartSerialPlot.Series.Add(series6);
            this.ChartSerialPlot.Size = new System.Drawing.Size(888, 537);
            this.ChartSerialPlot.TabIndex = 0;
            this.ChartSerialPlot.Text = "chart1";
            // 
            // TimerUpdate
            // 
            this.TimerUpdate.Interval = 1;
            this.TimerUpdate.Tick += new System.EventHandler(this.TimerUpdate_Tick);
            // 
            // ButtonClear
            // 
            this.ButtonClear.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.ButtonClear.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.ButtonClear.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.ButtonClear.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ButtonClear.ForeColor = System.Drawing.Color.White;
            this.ButtonClear.Location = new System.Drawing.Point(17, 236);
            this.ButtonClear.Name = "ButtonClear";
            this.ButtonClear.Size = new System.Drawing.Size(142, 34);
            this.ButtonClear.TabIndex = 11;
            this.ButtonClear.Text = "Clear Plot";
            this.ButtonClear.UseVisualStyleBackColor = true;
            this.ButtonClear.Click += new System.EventHandler(this.ButtonClear_Click);
            // 
            // label1
            // 
            this.label1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.SlateGray;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.White;
            this.label1.Location = new System.Drawing.Point(44, 16);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(77, 17);
            this.label1.TabIndex = 12;
            this.label1.Text = "COM Port";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoScroll = true;
            this.BackColor = System.Drawing.Color.SlateGray;
            this.ClientSize = new System.Drawing.Size(1059, 539);
            this.Controls.Add(this.PanelChart);
            this.Controls.Add(this.PanelButtons);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Name = "Form1";
            this.Text = "Accelerometer Data Stream";
            this.PanelButtons.ResumeLayout(false);
            this.PanelButtons.PerformLayout();
            this.PanelChart.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.ChartSerialPlot)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel PanelButtons;
        private System.Windows.Forms.Button ButtonClose;
        private System.Windows.Forms.Button ButtonOpen;
        private System.Windows.Forms.ComboBox ComboComBox;
        private System.Windows.Forms.Panel PanelChart;
        private System.Windows.Forms.DataVisualization.Charting.Chart ChartSerialPlot;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox TextBoxPortStatus;
        private System.Windows.Forms.Timer TimerUpdate;
        private System.Windows.Forms.Button ButtonClear;
        private System.Windows.Forms.Label label1;
    }
}

