			for(int i = n-1; i>0 and sum>k ; --i){
				sum+=v[0];
				sum-=v[i];
				v[i]=v[0];
				moves++;
			}
