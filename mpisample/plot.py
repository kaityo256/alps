import pyalps
import matplotlib.pyplot as plt
import pyalps.plot

data = pyalps.loadMeasurements(pyalps.getResultFiles(prefix='params'),(['Value']))
value = pyalps.collectXY(data,x='T', y='Value')
plt.figure()
pyalps.plot.plot(value)
plt.xlabel('T')
plt.ylabel('Value')
plt.title('Test Plot')
#plt.show()
plt.savefig("test.png")
