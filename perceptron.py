import random


y = [52,59,67,73,64,74,54,61,65,46,72]
data = [[132,137],[153,194],[143,184],[162,211],
[154,196],[168,220],[137,188],[149,188],[159,207],[128,167],[166,217]]




def learn(data,weights,learn_rate,iterations):
    k = 0
    while(True):
        for row in data:
            sumerror =0
            prediction = predict(row,weights)
            error = (prediction-row[-1])
            sumerror = sumerror + error**2
            if(sumerror<2):
                print("i think those are the best weights"+str(weights))
                break
            print("error:"+str(sumerror))
            for i in range(len(weights)):
                weights[i] = weights[i] - 0.00001*(error)*row[i]
        k+=1
        print(weights)


        



       



def predict(data,weights):
    output = 0
    for i in range(len(weights)):
        output = output + data[i]*weights[i]
    return output




          



            



def perceptron(data,output):
    #appending each observation data with 1,
    # to take in consideration the threshold weight.
    for i in data:
        i.append(1)
    for i in range(len(data)):
        data[i].append(output[i])
    dim = len(data[1])-1
    #initializing the weights vector.
    weights = []
    for i in range(0,dim):
        weights.append(0)
    
    learn(data,weights,0.0001,20)
    
    


    



    

perceptron(data,y)