#include &lt;iostream&gt;

#include &lt;vector&gt;

#include &lt;string&gt;

using namespace std;

int main()

{

int n;

cout&lt;&lt;&quot;\nEnter number of non terminals: &quot;;

cin&gt;&gt;n;

cout&lt;&lt;&quot;\nEnter non terminals one by one: &quot;;

int i;

vector&lt;string&gt; nonter(n);

vector&lt;int&gt; leftrecr(n,0);

for(i=0;i&lt;n;++i) {

cout&lt;&lt;&quot;\nNon terminal &quot;&lt;&lt;i+1&lt;&lt;&quot; : &quot;;

cin&gt;&gt;nonter[i];

}

vector&lt;vector&lt;string&gt; &gt; prod;

cout&lt;&lt;&quot;\nEnter &#39;^&#39; for null&quot;;

for(i=0;i&lt;n;++i) {

cout&lt;&lt;&quot;\nNumber of &quot;&lt;&lt;nonter[i]&lt;&lt;&quot; productions: &quot;;
int k;

cin&gt;&gt;k;

int j;

cout&lt;&lt;&quot;\nOne by one enter all &quot;&lt;&lt;nonter[i]&lt;&lt;&quot; productions&quot;;

vector&lt;string&gt; temp(k);

for(j=0;j&lt;k;++j) {

cout&lt;&lt;&quot;\nRHS of production &quot;&lt;&lt;j+1&lt;&lt;&quot;: &quot;;

string abc;

cin&gt;&gt;abc;

temp[j]=abc;

if(nonter[i].length()&lt;=abc.length()&amp;&amp;nonter[i].compare(abc.substr(0,nonter[i].length()))==0)

leftrecr[i]=1;

}

prod.push_back(temp);

}

for(i=0;i&lt;n;++i) {

cout&lt;&lt;leftrecr[i];

}

for(i=0;i&lt;n;++i) {

if(leftrecr[i]==0)

continue;

int j;

nonter.push_back(nonter[i]+&quot;&#39;&quot;);

vector&lt;string&gt; temp;

for(j=0;j&lt;prod[i].size();++j) {

if(nonter[i].length()&lt;=prod[i][j].length()&amp;&amp;nonter[i].compare(prod[i][j].substr(0,nonter[i].length
()))==0) {

string

abc=prod[i][j].substr(nonter[i].length(),prod[i][j].length()-nonter[i].length())+nonter[i]+&quot;&#39;&quot;;

temp.push_back(abc);

prod[i].erase(prod[i].begin()+j);

--j;

}

else {

prod[i][j]+=nonter[i]+&quot;&#39;&quot;;

}

}

temp.push_back(&quot;^&quot;);

prod.push_back(temp);

}

cout&lt;&lt;&quot;\n\n&quot;;

cout&lt;&lt;&quot;\nNew set of non-terminals: &quot;;

for(i=0;i&lt;nonter.size();++i)

cout&lt;&lt;nonter[i]&lt;&lt;&quot; &quot;;

cout&lt;&lt;&quot;\n\nNew set of productions: &quot;;

for(i=0;i&lt;nonter.size();++i) {

int j;

for(j=0;j&lt;prod[i].size();++j) {

cout&lt;&lt;&quot;\n&quot;&lt;&lt;nonter[i]&lt;&lt;&quot; -&gt; &quot;&lt;&lt;prod[i][j];

}

}

return 0;

}
