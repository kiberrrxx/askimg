# 🎨 askimg

A high-performance ASCII art generator written in C++ for Linux. 
Powered by **ImageMagick 7** for universal format support.

## ✨ Features
- **TrueColor Support**: Renders images using 24-bit ANSI colors.
- **Deep Precision**: Uses a 70-character palette for insane detail.
- **Ultra-Compatible**: Handles PNG, JPG, WebP, BMP, and more via Magick++.
- **Custom Geometry**: Manual width and height control.

## 🚀 Installation

### 1. Install Dependencies

#### **Gentoo**

Ensure ImageMagick is built with `cxx`, `jpeg`, and `png` flags:

# Add flags to /etc/portage/package.use/imagemagick:
media-gfx/imagemagick cxx jpeg png webp

```shell
sudo emerge --ask media-gfx/imagemagick
```

#### 🔖 Arch Linux

```shell
sudo pacman -S imagemagick
```

#### Debian / Ubuntu / Mint

```shell
sudo apt install libmagick++-dev
```

#### Fedora / Red Hat

```shell
sudo dnf install ImageMagick-c++-devel
```

### 📚 2. Build and Install

```bash
git clone https://github.com/your-username/askimg.git
cd askimg
make
sudo make install --prefix=/usr
```

##### The binary will be installed to /usr/bin/askimg.

### ✏️ 🛠 Usage

```shell
Flag      | Description                        
----------+------------------------------------
-w <n>    | Set width (default 100)            
-h <n>    | Set height (overrides auto-scaling)
-c        | TrueColor mode (24-bit ANSI)       
-i        | Invert luminance                   
-o <file> | Save clean ASCII text to a file
```

### 📚 Examples:

# View image in terminal with colors:

```shell
askimg -c -w 120 photo.jpg
```

Convert to 75x75 square and save to file:

```shell
askimg -w 75 -h 75 -o art.txt image.png
```

### ✏️ 🎨 Why askimg?

⦁ Magick++ Engine: Supports JPG, PNG, WebP, GIF, SVG, and more.
⦁ Precision Palette: Uses a 70-character density map for better shading.
⦁ Hyprland-inspired UI: Beautifully colored help and error messages.

————————

### Made, written and compiled by me (kiberrrxx)

# Created with ❤️ for the Linux community.


## 🖼️ Gallery

<p align="center">
 <img src="screenshots/prewiew.png" width="800px" alt="Screenshot 1"/>
 <br>
 <img src="screenshots/prewiew1.png" width="800px" alt="Screenshot 2"/>
 <br>
 <img src="screenshots/prewiew2.png" width="800px" alt="Screenshot 3"/>
 <br>
 <img src="screenshots/prewiew3.png" width="800px" alt="Screenshot 4"/>
</p>
