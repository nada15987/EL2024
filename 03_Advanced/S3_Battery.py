
from plyer import notification
import psutil

battery=psutil.sensors_battery()
percent=battery.percent
print(f"Battery percentage: {percent} %")
notification.notify(
    title="Battery Percentage",
    message=f"{percent}% percentage remaining",
    timeout=10
)