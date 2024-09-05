import ctypes
User32 = ctypes.WinDLL('User32.dll')
print(User32.GetSystemMetrics(1)) # Get the height of the primary monitor

sample = ctypes.WinDLL('.\\mydll.dll')
print(sample.mult(4,8))