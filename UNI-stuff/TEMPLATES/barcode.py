import cv2
import numpy as np
import pyzbar.pyzbar as pyzbar

# Initialize the VideoCapture object
cap = cv2.VideoCapture(0)

# Continuously capture frames from the webcam
while True:
    # Read a frame from the webcam
    ret, frame = cap.read()
    
    # Convert the frame to grayscale
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Use pyzbar to decode the barcode
    barcodes = pyzbar.decode(gray)

    # Loop over the barcodes
    for barcode in barcodes:
        # Extract the barcode data
        barcode_data = barcode.data.decode('utf-8')

        # Draw a rectangle around the barcode
        (x, y, w, h) = barcode.rect
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)

        # Display the barcode data
        cv2.putText(frame, barcode_data, (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)

    # Display the frame
    cv2.imshow('Barcode Scanner', frame)

    # Wait for a key press and check if the 'q' key was pressed
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the VideoCapture object and destroy all windows
cap.release()
cv2.destroyAllWindows()
