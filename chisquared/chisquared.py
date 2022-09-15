def getPercents (num_R, num_r, num_W, num_w):
    #kernel phenotypes
    numPurple = float(num_R)
    numYellow =float(num_r)
    numRound = float(num_W)
    numWrinkled = float(num_w)

    sumPhenotypes = float(numPurple + numYellow + numRound + numWrinkled)

    percent_R = numPurple/sumPhenotypes
    percent_r = numYellow/sumPhenotypes
    percent_W = numRound/sumPhenotypes
    percent_w = numWrinkled/sumPhenotypes

    result = (percent_R, percent_r, percent_W, percent_W, percent_w)


    return (result)

phenotypes = ("purple", "yellow", "round", "wrinkled")
percentPhenotypes = getPercents(10,10,10,10)
i = 0

for percentPhenotype in percentPhenotypes:
    print(percentPhenotype)
    print(phenotypes[i])
    print(f"{phenotype}")
    print(i)
    i += 1

def getChiSquaredAnalysis(actualPhenotypes, observedPhenotypes):
    print("hello")


