import tkinter as tk
import math

# Create the main window
window = tk.Tk()
window.title("Simple Gauge")
window.geometry("350x300")

# Create a label 
lbl=tk.Label(window,text="Humidity",font=("arial",15,"bold"),background="white",width=50)
lbl.pack()

# Create a canvas widget
canvas = tk.Canvas(window, width=350, height=300, bg="white")
canvas.pack()

# Draw arcs
'''
note:
-->style=ARC: This specifies that only the arc's outline should be drawn,
              not a filled sector.
-->start: This specifies the starting angle of the arc in degrees
-->extend: This specifies the angle that the arc extends from the starting angle.
''' 
coord = 50, 300, 300, 50
canvas.create_arc(coord, start=25, extent=125, outline="green", width=30, style=tk.ARC)
canvas.create_arc(coord, start=25, extent=50, outline="yellow", width=30, style=tk.ARC)
canvas.create_arc(coord, start=25, extent=26, outline="red", width=30, style=tk.ARC)

# Arc parameters
starting_angle = 25
extent_angle = 125
arc_center = (175, 175)
arc_radius = 120

# Draw dividing lines for the arcs
for angle in range(starting_angle, starting_angle + extent_angle + 1, 25):
    angle_rad = math.radians(angle)
    x = arc_center[0] + arc_radius * math.cos(angle_rad)
    y = arc_center[1] - arc_radius * math.sin(angle_rad)
    canvas.create_line(arc_center[0], arc_center[1], x, y, fill="black", width=1)

# Draw initial needle
current_angle = starting_angle
needle = canvas.create_line(
    arc_center[0], arc_center[1],
    arc_center[0] + arc_radius * math.cos(math.radians(current_angle)),
    arc_center[1] - arc_radius * math.sin(math.radians(current_angle)),
    fill="black", width=5
)

# Create a label to display the current value
value_label = tk.Label(window, text="0", font=("arial", 15, "bold"), background="white")
value_label.pack()


# Function to update the needle position
def update_needle(event):
    dx = event.x - arc_center[0]
    dy = arc_center[1] - event.y
    angle = math.degrees(math.atan2(dy, dx))

    # Normalize the angle to the range 0 to 100
    normalized_angle = (angle - starting_angle) % 360
    value = int(((126 - normalized_angle) / extent_angle) * 100)

    # Ensure the value is within 0 to 100
    value = max(0, min(100, value))

    # Update the label text with the current value
    value_label.config(text=f"{value} %")

    # Print the current value
    print("the current value is: ",value)

    # Update the needle position
    x = arc_center[0] + arc_radius * math.cos(math.radians(angle))
    y = arc_center[1] - arc_radius * math.sin(math.radians(angle))
    canvas.coords(needle, arc_center[0], arc_center[1], x, y)

     # Update the label position to be near the needle
    value_label.place(x=x, y=y - 20)


# Bind the drag event to the canvas
canvas.bind("<B1-Motion>", update_needle)

# Create text labels for 0 and 100 close to the arc
canvas.create_text(65, 125, text="0", font=("arial", 10))
canvas.create_text(290, 135, text="100", font=("arial", 10))

# Start the Tkinter event loop
window.mainloop()
