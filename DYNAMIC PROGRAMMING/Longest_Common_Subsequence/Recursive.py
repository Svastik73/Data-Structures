def funct(i,j,s,t):
    if i==len(s) or j==len(t):
        return 0;
    if s[i]==t[j]:
        return 1 + funct(i+1,j+1,s,t)
    else :
        return max(funct(i+1,j,s,t),funct(i,j+1,s,t))

ik=funct(0,0,"abcfb","bbcfac")
print(ik)

# output 3

