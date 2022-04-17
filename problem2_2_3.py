#霍夫直线检测
import cv2 as cv
import numpy as np

src = cv.imread('hough.png')

#将图像转换为灰度图像
gray = cv.cvtColor(src, cv.COLOR_BGR2GRAY)

#应用直方图均衡化
dst = cv.equalizeHist(gray)

#高斯滤波降噪
gaussian = cv.GaussianBlur(dst, (3,3), 0)

#利用Canny进行边缘检测
edges = cv.Canny(gaussian, 35,200, apertureSize=3)

#自动检测可能的直线
lines = cv.HoughLinesP(edges, 1, np.pi/180, 80, minLineLength=30, maxLineGap=60)
print(type(lines))
for line in lines:
    x1, y1, x2, y2 = line[0]
    cv.line(src, (x1, y1), (x2, y2), (0, 0, 255), 2)

cv.imshow("line",src)
cv.waitKey(0)
cv.destroyAllWindows()
