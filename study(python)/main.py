import cv2


pixels = cv2.imread("Test_Face.jpg")
cv2.imshow("Input photo", pixels)
face_cascade = cv2.CascadeClassifier("C:\XML\haarcascade_frontalface_alt.xml")
eye_cascade = cv2.CascadeClassifier("C:\XML\haarcascade_lefteye_2splits.xml")
gray = cv2.cvtColor(pixels, cv2.COLOR_BGR2GRAY)

faces = face_cascade.detectMultiScale(gray, 1.3, 5)
for (x, y, w, h) in faces:
    img = cv2.rectangle(pixels, (x, y), (x+w, y+h), (255, 0, 0), 2)
    roi_gray = gray[y:y+h, x:x+w]
    roi_color = img[y:y+h, x:x+w]
    eyes = eye_cascade.detectMultiScale(roi_gray)

    for (ex, ey, ew, eh) in eyes:
        cv2.rectangle(roi_color, (ex, ey), (ex+ew, ey+eh), (0, 255, 0), 2)

    cv2.imshow("Out_photo", pixels)
    cv2.imwrite("Test_Face_Eye.jpg", pixels)

    cv2.waitKey(0)
    cv2.destroyAllWindows()