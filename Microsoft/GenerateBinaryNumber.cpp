vector<string> generate(int N)
{
	// Your code here
	vector<string>res ;
	queue<string>q;
	q.push("1");
	for(int count=0 ; count<N ; count++){
	    string curr = q.front();
	    res.push_back(curr);
	    q.pop();
	    q.push(curr + '0');
	    q.push(curr + '1');
	}
	return res ;
}
