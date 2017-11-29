namespace Serial_Accelerometer
{
    partial class SerialAccelSplashScreen
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
            this.titleLabel = new System.Windows.Forms.Label();
            this.splashScreenProgressBar = new System.Windows.Forms.ProgressBar();
            this.SuspendLayout();
            // 
            // titleLabel
            // 
            this.titleLabel.BackColor = System.Drawing.SystemColors.Control;
            this.titleLabel.Dock = System.Windows.Forms.DockStyle.Top;
            this.titleLabel.Font = new System.Drawing.Font("Cambria", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.titleLabel.ForeColor = System.Drawing.Color.Black;
            this.titleLabel.Image = global::Serial_Accelerometer.Properties.Resources.graphIcon;
            this.titleLabel.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.titleLabel.Location = new System.Drawing.Point(0, 0);
            this.titleLabel.Name = "titleLabel";
            this.titleLabel.Size = new System.Drawing.Size(450, 137);
            this.titleLabel.TabIndex = 3;
            this.titleLabel.Text = "Serial Accelerometer\r\nTeam Hephaestus";
            this.titleLabel.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // splashScreenProgressBar
            // 
            this.splashScreenProgressBar.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.splashScreenProgressBar.Location = new System.Drawing.Point(0, 137);
            this.splashScreenProgressBar.Name = "splashScreenProgressBar";
            this.splashScreenProgressBar.Size = new System.Drawing.Size(450, 23);
            this.splashScreenProgressBar.TabIndex = 4;
            // 
            // SerialAccelSplashScreen
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(450, 160);
            this.ControlBox = false;
            this.Controls.Add(this.splashScreenProgressBar);
            this.Controls.Add(this.titleLabel);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "SerialAccelSplashScreen";
            this.ShowIcon = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "OrbitSimulationSplashScreen";
            this.Load += new System.EventHandler(this.SerialAccelSplashScreen_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label titleLabel;
        private System.Windows.Forms.ProgressBar splashScreenProgressBar;
    }
}