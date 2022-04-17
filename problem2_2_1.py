import imghdr
import cv2
import numpy as np
#rgb转hsv
def rgb2hsv(img): 
    h = img.shape[0]
    w = img.shape[1]
    H = np.zeros((h,w),np.float32)
    S = np.zeros((h, w), np.float32)
    V = np.zeros((h, w), np.float32)
    r,g,b = cv2.split(img)
    r, g, b = r/255.0, g/255.0, b/255.0
    for i in range(0, h):
        for j in range(0, w):
            mx = max((b[i, j], g[i, j], r[i, j]))
            mn = min((b[i, j], g[i, j], r[i, j]))
            V[i, j] = mx
            if V[i, j] == 0:
                S[i, j] = 0
            else:
                S[i, j] = (V[i, j] - mn) / V[i, j]
            if mx == mn:
                H[i, j] = 0
            elif V[i, j] == r[i, j]:
                if g[i, j] >= b[i, j]:
                    H[i, j] = (60 * ((g[i, j]) - b[i, j]) / (V[i, j] - mn))
                else:
                    H[i, j] = (60 * ((g[i, j]) - b[i, j]) / (V[i, j] - mn))+360
            elif V[i, j] == g[i, j]:
                H[i, j] = 60 * ((b[i, j]) - r[i, j]) / (V[i, j] - mn) + 120
            elif V[i, j] == b[i, j]:
                H[i, j] = 60 * ((r[i, j]) - g[i, j]) / (V[i, j] - mn) + 240
            H[i,j] = H[i,j] / 2
    return H, S, V


img=cv2.imread('lena.jpg')
grayimg=cv2.imread('lena.jpg',0)#直接使用imread(src,value) 将value的值设置为0为灰度图读取
cv2.imshow('image',img)#原图
cv2.imshow('grayimgae',grayimg)#灰度图
h,s,v = rgb2hsv(img)
merged = cv2.merge([h,s,v]) 
cv2.imshow("hsvimage",merged) #hsv图
cv2.waitKey(0)
cv2.destroyAllWindows()

