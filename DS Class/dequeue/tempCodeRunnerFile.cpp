int count =0;
        deque<char>d;
        map<char,int>m;
        for (int i = 0 ; i < s.size(); i++  ){
            if(s[i]!='a' and s[i]!='e' and s[i]!='i' and s[i]!='o' and s[i]!='u'){ 
                while(!d.empty()){
                    d.pop_back();
                }
                m.clear();
            }
            else{
                d.push_back(s[i]);
                
                m[s[i]]++;

                if (m['a']>0 and m['e']>0 and m['i']>0 and m['o']>0 and m['u']>0)
                {
                    count++;
                    if(d.size()>5){
                        int k = 0;
                        while(d.size()-k>5){
                            if(m[d[k]]>1){
                                count++;
                            }
                            else{
                                break;
                            }
                            k++;
                        }
                    }
                }

            }
        }