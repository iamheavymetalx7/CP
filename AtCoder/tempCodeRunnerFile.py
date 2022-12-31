                if arr[i][j]=="o" or arr[j][i]=="o":
                    seen.add((i,j))
                    seen.add((j,i))
                    cnt+=1