#include&lt;stdio.h&gt;
#include&lt;string.h&gt;
int main()
{
char reg[20];
int q[20][3],i,j,len,a,b;
for(a=0;a&lt;20;a++)
{
for(b=0;b&lt;3;b++)
{
q[a][b]=0;
}
}
printf(&quot;Enter the regular expression:&quot;);
scanf(&quot;%s&quot;,reg);
len=strlen(reg);
i=0;
j=1;
while(i&lt;len)
{
if(reg[i]==&#39;a&#39;&amp;&amp;reg[i+1]!=&#39;|&#39;&amp;&amp;reg[i+1]!=&#39;*&#39;)
{
q[j][0]=j+1;
j++;
}
if(reg[i]==&#39;b&#39;&amp;&amp;reg[i+1]!=&#39;|&#39;&amp;&amp;reg[i+1]!=&#39;*&#39;)
{
q[j][1]=j+1;
j++;

}
if(reg[i]==&#39;e&#39;&amp;&amp;reg[i+1]!=&#39;|&#39;&amp;&amp;reg[i+1]!=&#39;*&#39;)
{
q[j][2]=j+1;
j++;
}
if(reg[i]==&#39;a&#39;&amp;&amp;reg[i+1]==&#39;|&#39;&amp;&amp;reg[i+2]==&#39;b&#39;)
{
q[j][2]=((j+1)*10)+(j+3);
j++;
q[j][0]=j+1;
j++;
q[j][2]=j+3;
j++;
q[j][1]=j+1;
j++;
q[j][2]=j+1;
j++;
i=i+2;
}
if(reg[i]==&#39;b&#39;&amp;&amp;reg[i+1]==&#39;|&#39;&amp;&amp;reg[i+2]==&#39;a&#39;)
{
q[j][2]=((j+1)*10)+(j+3);
j++;
q[j][1]=j+1;
j++;
q[j][2]=j+3;
j++;
q[j][0]=j+1;
j++;
q[j][2]=j+1;
j++;
i=i+2;
}
if(reg[i]==&#39;a&#39;&amp;&amp;reg[i+1]==&#39;*&#39;)
{
q[j][2]=((j+1)*10)+(j+3);
j++;
q[j][0]=j+1;
j++;
q[j][2]=((j+1)*10)+(j-1);
j++;
}
if(reg[i]==&#39;b&#39;&amp;&amp;reg[i+1]==&#39;*&#39;)
{
q[j][2]=((j+1)*10)+(j+3);
j++;
q[j][1]=j+1;
j++;
q[j][2]=((j+1)*10)+(j-1);
j++;
}
if(reg[i]==&#39;)&#39;&amp;&amp;reg[i+1]==&#39;*&#39;)
{
q[0][2]=((j+1)*10)+1;

q[j][2]=((j+1)*10)+1;
j++;
}
i++;
}
printf(&quot;Transition function \n&quot;);
for(i=0;i&lt;=j;i++)
{
if(q[i][0]!=0)
printf(&quot;\n q[%d,a]--&gt;%d&quot;,i,q[i][0]);
if(q[i][1]!=0)
printf(&quot;\n q[%d,b]--&gt;%d&quot;,i,q[i][1]);
if(q[i][2]!=0)
{
if(q[i][2]&lt;10)
printf(&quot;\n q[%d,e]--&gt;%d&quot;,i,q[i][2]);
else
printf(&quot;\n q[%d,e]--&gt;%d &amp; %d&quot;,i,q[i][2]/10,q[i][2]%10);

}
}
return 0;
}
