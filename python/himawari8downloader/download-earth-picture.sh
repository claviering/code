echo ""
echo "Usage"
echo "python himawari8downloader.py fout scale"
echo "fout is the path of the output image file"
echo "scale set the size of the result image.The result image's width and height are both scale×550. scale can be 1, 2, 4, 8, 16, 20"
echo ""
echo "For example:"
echo "      python himawari8downloader.py earth.png 2"
echo ""
python ~/code/python/himawari8downloader/himawari8downloader.py earth.png 1
eog earth.png
