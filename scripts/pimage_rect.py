import cv2
import sys

def draw_direct(img_file, rect_file, resave_image="out.jpg"):
	image = cv2.imread(img_file)
	with open(rect_file, "r") as fd:
		lines = map(lambda x: map(float, x.strip().split()), fd.readlines())
		for rect in lines:
			xmin, ymin, xmax, ymax = rect[:4]
			cv2.rectangle(image, (xmin, ymin), (xmax, ymax), (0, 0, 255), 2)
			if len(rect) > 4:
				font=cv2.FONT_HERSHEY_SIMPLEX
				cv2.putText(image, rect[4], (xmax, ymin), font, 4, (0, 0, 255), 2)
	cv2.imwrite(resave_image, image)


if __name__ == '__main__':
	draw_direct(sys.argv[1], sys.argv[2], sys.argv[3])