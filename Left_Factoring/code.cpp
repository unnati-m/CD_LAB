#include &lt;iostream&gt;

#include &lt;math.h&gt;

#include &lt;vector&gt;

#include &lt;string&gt;

#include &lt;stdlib.h&gt;

using namespace std;

int main()

{

cout&lt;&lt;&quot;\nEnter number of productions: &quot;;

int p;

cin&gt;&gt;p;

vector&lt;string&gt; prodleft(p),prodright(p);

cout&lt;&lt;&quot;\nEnter productions one by one: &quot;;

int i;

for(i=0;i&lt;p;++i) {

cout&lt;&lt;&quot;\nLeft of production &quot;&lt;&lt;i+1&lt;&lt;&quot;: &quot;;

cin&gt;&gt;prodleft[i];

cout&lt;&lt;&quot;\nRight of production &quot;&lt;&lt;i+1&lt;&lt;&quot;: &quot;;

cin&gt;&gt;prodright[i];

}

int j;

int e=1;

for(i=0;i&lt;p;++i) {

for(j=i+1;j&lt;p;++j) {

if(prodleft[j]==prodleft[i]) {

int k=0;

string com=&quot;&quot;;

while(k&lt;prodright[i].length()&amp;&amp;k&lt;prodright[j].length()&amp;&amp;prodright[i][k]==prodright[j][k]) {

com+=prodright[i][k];

++k;

}

if(k==0)

continue;

char* buffer;

string comleft=prodleft[i];

if(k==prodright[i].length()) {

prodleft[i]+=string(itoa(e,buffer,10));

prodleft[j]+=string(itoa(e,buffer,10));

prodright[i]=&quot;^&quot;;

prodright[j]=prodright[j].substr(k,prodright[j].length()-k);

}

else if(k==prodright[j].length()) {

prodleft[i]+=string(itoa(e,buffer,10));

prodleft[j]+=string(itoa(e,buffer,10));

prodright[j]=&quot;^&quot;;

prodright[i]=prodright[i].substr(k,prodright[i].length()-k);

}

else {

prodleft[i]+=string(itoa(e,buffer,10));

prodleft[j]+=string(itoa(e,buffer,10));

prodright[j]=prodright[j].substr(k,prodright[j].length()-k);

prodright[i]=prodright[i].substr(k,prodright[i].length()-k);

}

int l;

for(l=j+1;l&lt;p;++l) {

if(comleft==prodleft[l]&amp;&amp;com==prodright[l].substr(0,fmin(k,prodright[l].length()))) {

prodleft[l]+=string(itoa(e,buffer,10));

prodright[l]=prodright[l].substr(k,prodright[l].length()-k);

}

}

prodleft.push_back(comleft);

prodright.push_back(com+prodleft[i]);

++p;

++e;

}

}

}

cout&lt;&lt;&quot;\n\nNew productions&quot;;

for(i=0;i&lt;p;++i) {

cout&lt;&lt;&quot;\n&quot;&lt;&lt;prodleft[i]&lt;&lt;&quot;-&gt;&quot;&lt;&lt;prodright[i];

}

return 0; }
