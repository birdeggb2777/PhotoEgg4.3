namespace PhotoEgg4._3
{
    partial class DrawForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(DrawForm));
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.檔案ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.載入圖片ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.splitter1 = new System.Windows.Forms.Splitter();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.PenSizeText1 = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.imageList2 = new System.Windows.Forms.ImageList(this.components);
            this.tabControl2 = new System.Windows.Forms.TabControl();
            this.tabPage6 = new System.Windows.Forms.TabPage();
            this.SelectFullColor_Picture = new System.Windows.Forms.PictureBox();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.menuStrip1.SuspendLayout();
            this.tabControl1.SuspendLayout();
            this.tabPage3.SuspendLayout();
            this.tabControl2.SuspendLayout();
            this.tabPage6.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.SelectFullColor_Picture)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // menuStrip1
            // 
            this.menuStrip1.BackColor = System.Drawing.SystemColors.AppWorkspace;
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(21, 21);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.檔案ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1044, 28);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 檔案ToolStripMenuItem
            // 
            this.檔案ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.載入圖片ToolStripMenuItem});
            this.檔案ToolStripMenuItem.Name = "檔案ToolStripMenuItem";
            this.檔案ToolStripMenuItem.Size = new System.Drawing.Size(55, 24);
            this.檔案ToolStripMenuItem.Text = "檔案";
            // 
            // 載入圖片ToolStripMenuItem
            // 
            this.載入圖片ToolStripMenuItem.Name = "載入圖片ToolStripMenuItem";
            this.載入圖片ToolStripMenuItem.Size = new System.Drawing.Size(159, 30);
            this.載入圖片ToolStripMenuItem.Text = "載入圖片";
            this.載入圖片ToolStripMenuItem.Click += new System.EventHandler(this.載入圖片ToolStripMenuItem_Click);
            // 
            // splitter1
            // 
            this.splitter1.Location = new System.Drawing.Point(0, 28);
            this.splitter1.Name = "splitter1";
            this.splitter1.Size = new System.Drawing.Size(477, 787);
            this.splitter1.TabIndex = 1;
            this.splitter1.TabStop = false;
            // 
            // tabControl1
            // 
            this.tabControl1.Alignment = System.Windows.Forms.TabAlignment.Left;
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Controls.Add(this.tabPage3);
            this.tabControl1.ImageList = this.imageList2;
            this.tabControl1.Location = new System.Drawing.Point(12, 43);
            this.tabControl1.Multiline = true;
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(340, 287);
            this.tabControl1.TabIndex = 2;
            // 
            // tabPage1
            // 
            this.tabPage1.ImageIndex = 0;
            this.tabPage1.Location = new System.Drawing.Point(55, 4);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(281, 279);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // tabPage2
            // 
            this.tabPage2.ImageIndex = 2;
            this.tabPage2.Location = new System.Drawing.Point(55, 4);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(281, 279);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.PenSizeText1);
            this.tabPage3.Controls.Add(this.label1);
            this.tabPage3.ImageIndex = 4;
            this.tabPage3.Location = new System.Drawing.Point(55, 4);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage3.Size = new System.Drawing.Size(281, 279);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // PenSizeText1
            // 
            this.PenSizeText1.Font = new System.Drawing.Font("新細明體", 17.856F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.PenSizeText1.Location = new System.Drawing.Point(150, 21);
            this.PenSizeText1.MaxLength = 2;
            this.PenSizeText1.Name = "PenSizeText1";
            this.PenSizeText1.Size = new System.Drawing.Size(80, 45);
            this.PenSizeText1.TabIndex = 1;
            this.PenSizeText1.Text = "15";
            this.PenSizeText1.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.PenSizeText1_KeyPress);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("新細明體", 17.856F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.label1.Location = new System.Drawing.Point(6, 24);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(143, 32);
            this.label1.TabIndex = 0;
            this.label1.Text = "筆刷大小";
            // 
            // imageList2
            // 
            this.imageList2.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList2.ImageStream")));
            this.imageList2.TransparentColor = System.Drawing.Color.Transparent;
            this.imageList2.Images.SetKeyName(0, "Left_Point.png");
            this.imageList2.Images.SetKeyName(1, "Left_Point_Click.png");
            this.imageList2.Images.SetKeyName(2, "Left_Hand.png");
            this.imageList2.Images.SetKeyName(3, "Left_Hand1.png");
            this.imageList2.Images.SetKeyName(4, "Left_Brush.png");
            this.imageList2.Images.SetKeyName(5, "Left_Brush_Click.png");
            this.imageList2.Images.SetKeyName(6, "color.png");
            // 
            // tabControl2
            // 
            this.tabControl2.Alignment = System.Windows.Forms.TabAlignment.Left;
            this.tabControl2.Controls.Add(this.tabPage6);
            this.tabControl2.ImageList = this.imageList2;
            this.tabControl2.Location = new System.Drawing.Point(12, 348);
            this.tabControl2.Multiline = true;
            this.tabControl2.Name = "tabControl2";
            this.tabControl2.SelectedIndex = 0;
            this.tabControl2.Size = new System.Drawing.Size(406, 435);
            this.tabControl2.TabIndex = 3;
            // 
            // tabPage6
            // 
            this.tabPage6.Controls.Add(this.SelectFullColor_Picture);
            this.tabPage6.Controls.Add(this.pictureBox1);
            this.tabPage6.ImageIndex = 6;
            this.tabPage6.Location = new System.Drawing.Point(55, 4);
            this.tabPage6.Name = "tabPage6";
            this.tabPage6.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage6.Size = new System.Drawing.Size(347, 427);
            this.tabPage6.TabIndex = 1;
            this.tabPage6.UseVisualStyleBackColor = true;
            // 
            // SelectFullColor_Picture
            // 
            this.SelectFullColor_Picture.Image = global::PhotoEgg4._3.Properties.Resources.ColorFull;
            this.SelectFullColor_Picture.Location = new System.Drawing.Point(288, 6);
            this.SelectFullColor_Picture.Name = "SelectFullColor_Picture";
            this.SelectFullColor_Picture.Size = new System.Drawing.Size(38, 360);
            this.SelectFullColor_Picture.TabIndex = 2;
            this.SelectFullColor_Picture.TabStop = false;
            this.SelectFullColor_Picture.MouseDown += new System.Windows.Forms.MouseEventHandler(this.SelectFullColor_Picture_MouseDown);
            this.SelectFullColor_Picture.MouseMove += new System.Windows.Forms.MouseEventHandler(this.SelectFullColor_Picture_MouseMove);
            this.SelectFullColor_Picture.MouseUp += new System.Windows.Forms.MouseEventHandler(this.SelectFullColor_Picture_MouseUp);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::PhotoEgg4._3.Properties.Resources.chooseColor_Rec;
            this.pictureBox1.Location = new System.Drawing.Point(6, 41);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(255, 255);
            this.pictureBox1.TabIndex = 1;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.Picture_MouseDown);
            this.pictureBox1.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Picture_MouseMove);
            this.pictureBox1.MouseUp += new System.Windows.Forms.MouseEventHandler(this.Picture_MouseUp);
            // 
            // DrawForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.ClientSize = new System.Drawing.Size(1044, 815);
            this.Controls.Add(this.tabControl2);
            this.Controls.Add(this.tabControl1);
            this.Controls.Add(this.splitter1);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "DrawForm";
            this.Text = "DrawForm";
            this.Load += new System.EventHandler(this.DrawForm_Load);
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.Form_MouseDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Form_MouseMove);
            this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.Form_MouseUp);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.tabControl1.ResumeLayout(false);
            this.tabPage3.ResumeLayout(false);
            this.tabPage3.PerformLayout();
            this.tabControl2.ResumeLayout(false);
            this.tabPage6.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.SelectFullColor_Picture)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 檔案ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 載入圖片ToolStripMenuItem;
        private System.Windows.Forms.Splitter splitter1;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.ImageList imageList2;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.TextBox PenSizeText1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TabControl tabControl2;
        private System.Windows.Forms.TabPage tabPage6;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.PictureBox SelectFullColor_Picture;
    }
}