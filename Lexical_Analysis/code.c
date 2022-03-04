#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#include&lt;string.h&gt;
#include&lt;ctype.h&gt;
#include&lt;vector&gt;

int isKeyword(char buffer[]){

char keywords[40][20] =
{&quot;class&quot;,&quot;string&quot;,&quot;main&quot;,&quot;auto&quot;,&quot;using&quot;,&quot;namespace&quot;,&quot;include&quot;,&quot;break&quot;,&quot;case&quot;,&quot;
char&quot;,&quot;const&quot;,&quot;continue&quot;,&quot;default&quot;,
&quot;do&quot;,&quot;double&quot;,&quot;else&quot;,&quot;enum&quot;,&quot;extern&quot;,&quot;float&quot;,&quot;for&quot;,&quot;goto&quot;,
&quot;if&quot;,&quot;int&quot;,&quot;long&quot;,&quot;public&quot;,&quot;register&quot;,&quot;return&quot;,&quot;short&quot;,&quot;signed&quot;,
&quot;sizeof&quot;,&quot;static&quot;,&quot;struct&quot;,&quot;switch&quot;,&quot;typedef&quot;,&quot;union&quot;,
&quot;unsigned&quot;,&quot;void&quot;,&quot;volatile&quot;,&quot;while&quot;};

int i, flag = 0;
for(i = 0; i &lt; 32; ++i){
if(strcmp(keywords[i], buffer) == 0){
flag = 1;
break;
}
}
return flag;
}

char isHeader(char buffer[]){
char headers[2][10] = {
&quot;iostream&quot;, &quot;stdio&quot;
};

int i, flag = 0;
for(i = 0; i &lt; 2; ++i){
if(strcmp(headers[i], buffer) == 0){
flag = 1;

break;
}
}
return flag;
}

int main(){
char ch, buffer[15], operators[] = &quot;+-*/%=&lt;&gt;&quot;, special[] = &quot;#;,.{}[]()&quot;;
FILE *fp;
int i,j=0;
fp = fopen(&quot;sample.txt&quot;,&quot;r&quot;);
if(fp == NULL){
printf(&quot;error while opening the file\n&quot;);
exit(0);
}
while((ch = fgetc(fp)) != EOF){
for(i = 0; i &lt; 8; ++i){
if(ch == operators[i])
printf(&quot;%c is operator\n&quot;, ch);
}

for(i = 0; i &lt; 10; ++i){
if(ch == special[i])
printf(&quot;%c is special character\n&quot;, ch);
}

if(isdigit(ch)==true)
printf(&quot;%c is an integer\n&quot;,ch);

if(isalnum(ch)){
buffer[j++] = ch;
}
else if((ch == &#39; &#39; || ch == &#39;\n&#39;) &amp;&amp; (j != 0)){
buffer[j] = &#39;\0&#39;;
j = 0;

if(isKeyword(buffer) == 1)
printf(&quot;%s is keyword\n&quot;, buffer);
else if(isHeader(buffer)==1)
printf(&quot;%s is Header file\n&quot;, buffer);
else
printf(&quot;%s is identifier\n&quot;, buffer);
}

}
fclose(fp);
return 0;
}
