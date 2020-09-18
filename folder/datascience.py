import csv
import matplotlib.pyplot as plt

with open('Gapminder.csv', 'r') as myFile:
    data = list(csv.reader(myFile, delimiter=','))

def dataTypeConversion(rawList, dataType):
    convertedList = []
    previousValue = 0
    for item in rawList:
        if item != '':
            convertedList.append(dataType(item))
            previousValue = dataType(item)
        else:
            convertedList.append(previousValue) # replacing missing value with previous value
    return convertedList

def fetchIndices(data, columnIndex, searchItem):
    listRowIndices = []

    for i in range(len(data)):
        if data[i][columnIndex] == searchItem:
            listRowIndices.append(i)
    
    return listRowIndices

def fetchColumnData(data, columnIndex, hasHeader):
    listData = []

    for i in range(len(data)):
        listData.append(data[i][columnIndex])
    if hasHeader:
        return listData[1:]
    else:
        return listData

def fetchData(data, columnIndex, listRowIndices):
    listDataValues = []

    for i in range(len(listRowIndices)):
        listDataValues.append(data[listRowIndices[i]][columnIndex])
    return listDataValues


paksitanIndices = fetchIndices(data,0,'Pakistan')
years = dataTypeConversion(fetchData(data,4,paksitanIndices),int)

countries = set(fetchColumnData(data,0,True))
indicators = data[0][6:]
print(indicators)


countriesDict = {}

for countryName in countries:
    countryIndices = fetchIndices(data,0,countryName)
    for indicatorName in indicators:
        countriesDict[(countryName,indicatorName)] = dataTypeConversion(fetchData(data,data[0].index(indicatorName),countryIndices),float)

'''
print(sum(countriesDict[('Norway','DemocracyScore')])/len(years))
print(sum(countriesDict[('Norway','EnergyUsePerPerson')])/len(years))
print(sum(countriesDict[('Norway','Exports')])/len(years))
print(sum(countriesDict[('Norway','Femalesaged25to54labourforceparticipationrate')])/len(years))
print(sum(countriesDict[('Norway','Imports')])/len(years))
print(sum(countriesDict[('Norway','Taxrevenue')])/len(years))
print(sum(countriesDict[('Norway','YearlyCO2emission')])/len(years))




for indicatorName in indicators:
    plt.figure()
    plt.plot(years, countriesDict[('Pakistan',indicatorName)], 'green', label="Pakistan")
    plt.plot(years, countriesDict[('India',indicatorName)], 'red', label="India")
    plt.plot(years, countriesDict[('United States of America',indicatorName)], 'blue', label="USA")
    plt.plot(years, countriesDict[('China',indicatorName)], 'black', label="China")
    plt.plot(years, countriesDict[('Somalia',indicatorName)], 'orange', label="Somalia")
    plt.plot(years, countriesDict[('Bangladesh',indicatorName)], 'yellow', label="Bangladesh")
    plt.plot(years, countriesDict[('United Kingdom',indicatorName)], 'cyan', label="UK")
    plt.plot(years, countriesDict[('Norway',indicatorName)], 'magenta', label="Norway")
    plt.title(indicatorName)
    plt.legend(loc="best")

plt.show()'''
