#include<stdio.h>
int main(){
            float math,chem,phy,com,eng,bio;
            float theorymath,theorychem,theoryphy,theoryeng;
            float mcqmath,mcqchem,mcqphy,mcqeng;
            float min, max,totaltheory, average, percentage,theorymax,theorymin;
            float maxmcq,minmcq,totalmcq,allTotal;
            float meritTotal,meritPer,theorybio,mcqbio;
            int a;

            printf("\n Please enter your Group \n");

            printf("\n Select 1 for A group or Select 2 for B group :: ");
            scanf("%d",&a);

            printf("\n Please use Enter key after adding your marks. \n");

            if(a==1){
                    printf("Enter Marks of Maths theory (out of 50) :: ");
            scanf("%f",&theorymath);
            
            printf("Enter Marks of Chemistry theory (out of 50) :: ");
            scanf("%f",&theorychem);
            
             printf("Enter Marks of Physics theory (out of 50) :: ");
            scanf("%f",&theoryphy);
            
            printf("Enter Marks of Computer theory (out of 100) :: ");
            scanf("%f",&com);
            
            printf("Enter Marks of English theory (out of 50) :: ");
            scanf("%f",&theoryeng);

            printf("Enter Marks of Maths Mcq (out of 50) :: ");
            scanf("%f",&mcqmath);
            
            printf("Enter Marks of Chemistry Mcq (out of 50) :: ");
            scanf("%f",&mcqchem);
            
             printf("Enter Marks of Physics Mcq (out of 50) :: ");
            scanf("%f",&mcqphy);
            
            printf("Enter Marks of English Mcq (out of 50) :: ");
            scanf("%f",&mcqeng);


            theorymax = (theorymath > theorychem && 
                      theorymath > theoryphy &&  
                      theorymath > theoryeng) 
                      ? (theorymath) 
                        : (theorychem > theoryeng && 
                         theorychem > theoryphy ) ? (theorychem)
                      : (theoryphy > theoryeng ) ? (theoryphy) : (theoryeng);

            theorymin = (theorymath < theorychem && 
                      theorymath < theoryphy &&  
                      theorymath < theoryeng ) 
                      ? (theorymath) 
                        : (theorychem < theoryeng && 
                         theorychem < theoryphy) ? (theorychem)
                      : (theoryphy < theoryeng
                        ) ? (theoryphy): (theoryeng);           
                      
         maxmcq = (mcqmath > mcqchem && 
                      mcqmath > mcqphy && 
                      mcqmath > mcqeng ) 
                      ? (mcqmath) 
                        : (mcqchem > mcqeng && 
                         mcqchem > mcqphy) ? (mcqchem)
                      : (mcqphy > mcqeng
                        ) ? (mcqphy)
                      : (mcqeng);

                      
          minmcq = (mcqmath < mcqchem && 
                      mcqmath < mcqphy && 
                      mcqmath < mcqeng ) 
                      ? (mcqmath) 
                        : (mcqchem < mcqeng && 
                         mcqchem < mcqphy) ? (mcqchem)
                      : (mcqphy < mcqeng 
                        ) ? (mcqphy) : (mcqeng);

                    math = theorymath + mcqmath; 
                    chem = theorychem + mcqchem;
                    phy = theoryphy + mcqphy; 
                    eng = theoryeng + mcqeng;

                    max = (math > chem && 
                      math > phy && 
                      math > com && 
                      math > eng) 
                      ? (math) 
                        : (chem > eng && 
                         chem > phy &&
                         chem > com ) ? (chem)
                      : (phy > com &&
                          phy > eng ) ? (phy)
                      : (com > eng  ) ? (com) : (eng);

                    min = (math < chem && 
                      math < phy && 
                      math < com && 
                      math < eng ) 
                      ? (math) 
                        : (chem < eng && 
                         chem < phy &&
                         chem < com
                         ) ? (chem)
                      : (phy < com &&
                          phy < eng
                        ) ? (phy)
                      : (com < eng 
                          ) ? (com) : (eng);                      
                            
                     totaltheory = theorymath + theoryphy + theorychem + theoryeng;
                     totalmcq = mcqmath + mcqphy + mcqchem + mcqeng + com;
                     
                     allTotal = totaltheory + totalmcq;
                     average =allTotal / 5.0;
                     percentage = (allTotal / 500.0) * 100;
                     
                     printf("\n The Maximum Theory marks you get between Math %.f,Chem %.f,Phy %.f and Eng %.f is :: %.f \n",theorymath,theorychem,theoryphy,theoryeng,theorymax);
                     printf("\n The Maximum Mcq marks you get between %.f, %.f, %.f and %.f is :: %.f \n",mcqmath,mcqchem,mcqphy,mcqeng,maxmcq);                     
                     printf("\n The Minimum Theory marks you get between %.f, %.f, %.f and %.f is :: %.f \n",theorymath,theorychem,theoryphy,theoryeng,theorymin);
                     printf("\n The Minimum Mcq marks you get between %.f, %.f, %.f and %.f is :: %.f \n",mcqmath,mcqchem,mcqphy,mcqeng,minmcq);
                    printf("\n The Maximum Theory marks you get between %.f, %.f, %.f, %.f and %.f is :: %.f \n",math,chem,phy,com,eng,max);
                    printf("\n The Maximum Theory marks you get between %.f, %.f, %.f, %.f and %.f is :: %.f \n",math,chem,phy,com,eng,min);
                     printf("\n Total Marks is :: %.2f \n",allTotal);
                     
                     printf("\n Average Marks is :: %.2f \n",average);
                     
                     printf("\n Percentage is :: %.2f \n",percentage);


                     meritTotal = math + chem + phy;
                     meritPer = ((meritTotal) * 100) / 300;

                     printf("Your merit total is :: '%.f' \n",meritTotal);
                     printf("Your merit Percentage is :: '%.f' \n",meritPer);
                    
                     if(percentage >= 90 ){
                               printf("\n  Grade 'A' \n");
                               printf("\n Congratulaions you are passed with Very Good Marks... :) \n");
                         }
                else if(percentage >= 80 ){
                               printf("\n  Grade 'B' \n");
                               printf("\n Congratulaions you are passed with Very Good Marks... :) \n");
                         }
                else if(percentage >= 70 ){
                               printf("\n  Grade 'C' \n");
                               printf("\n Congratulaions you are passed with average Marks... :|  \n");
          }                          
                else if(percentage >= 60 ){
                               printf("\n  Grade 'D' \n");
                               printf("\n Congratulaions you are passed with average Marks... :|  \n");               }
                              
                   else if(percentage >= 50 ){
                               printf("\n  Grade 'E' \n");
                               printf("\n Congratulaions you are passed... :) \n");
                               }    
                else if(percentage <= 37 ){
                               printf("\n  Grade 'F' \n");
                               printf("\n Sorry better luck next time you are failed... :( \n");
                               }




            }

            if(a == 2){
              printf("Enter Marks of Bio theory (out of 50) :: ");
            scanf("%f",&theorybio);
            
            printf("Enter Marks of Chemistry theory (out of 50) :: ");
            scanf("%f",&theorychem);
            
             printf("Enter Marks of Physics theory (out of 50) :: ");
            scanf("%f",&theoryphy);
            
            printf("Enter Marks of Computer theory (out of 100) :: ");
            scanf("%f",&com);
            
            printf("Enter Marks of English theory (out of 50) :: ");
            scanf("%f",&theoryeng);

            printf("Enter Marks of Bio Mcq (out of 50) :: ");
            scanf("%f",&mcqbio);
            
            printf("Enter Marks of Chemistry Mcq (out of 50) :: ");
            scanf("%f",&mcqchem);
            
             printf("Enter Marks of Physics Mcq (out of 50) :: ");
            scanf("%f",&mcqphy);
            
            printf("Enter Marks of English Mcq (out of 50) :: ");
            scanf("%f",&mcqeng);


            theorymax = (theorybio > theorychem && 
                      theorybio > theoryphy &&  
                      theorybio > theoryeng) 
                      ? (theorybio) 
                        : (theorychem > theoryeng && 
                         theorychem > theoryphy ) ? (theorychem)
                      : (theoryphy > theoryeng ) ? (theoryphy) : (theoryeng);

            theorymin = (theorybio < theorychem && 
                      theorybio < theoryphy &&  
                      theorybio < theoryeng ) 
                      ? (theorybio) 
                        : (theorychem < theoryeng && 
                         theorychem < theoryphy) ? (theorychem)
                      : (theoryphy < theoryeng
                        ) ? (theoryphy): (theoryeng);           
                      
         maxmcq = (mcqbio > mcqchem && 
                      mcqbio > mcqphy && 
                      mcqbio > mcqeng ) 
                      ? (mcqbio) 
                        : (mcqchem > mcqeng && 
                         mcqchem > mcqphy) ? (mcqchem)
                      : (mcqphy > mcqeng
                        ) ? (mcqphy)
                      : (mcqeng);

                      
          minmcq = (mcqbio < mcqchem && 
                      mcqbio < mcqphy && 
                      mcqbio < mcqeng ) 
                      ? (mcqbio) 
                        : (mcqchem < mcqeng && 
                         mcqchem < mcqphy) ? (mcqchem)
                      : (mcqphy < mcqeng 
                        ) ? (mcqphy) : (mcqeng);

                    bio = theorybio + mcqbio; 
                    chem = theorychem + mcqchem;
                    phy = theoryphy + mcqphy; 
                    eng = theoryeng + mcqeng;

                    max = (bio > chem && 
                      bio > phy && 
                      bio > com && 
                      bio > eng) 
                      ? (bio) 
                        : (chem > eng && 
                         chem > phy &&
                         chem > com ) ? (chem)
                      : (phy > com &&
                          phy > eng ) ? (phy)
                      : (com > eng  ) ? (com) : (eng);

                    min = (bio < chem && 
                      bio < phy && 
                      bio < com && 
                      bio < eng ) 
                      ? (bio) 
                        : (chem < eng && 
                         chem < phy &&
                         chem < com
                         ) ? (chem)
                      : (phy < com &&
                          phy < eng
                        ) ? (phy)
                      : (com < eng 
                          ) ? (com) : (eng);                      
                            
                     totaltheory = theorybio + theoryphy + theorychem + theoryeng;
                     totalmcq = mcqbio + mcqphy + mcqchem + mcqeng + com;
                     
                     allTotal = totaltheory + totalmcq;
                     average =allTotal / 5.0;
                     percentage = (allTotal / 500.0) * 100;
                     
                     printf("\n The Maximum Theory marks you get between Math %.f,Chem %.f,Phy %.f and Eng %.f is :: %.f \n",theorybio,theorychem,theoryphy,theoryeng,theorymax);
                     printf("\n The Maximum Mcq marks you get between %.f, %.f, %.f and %.f is :: %.f \n",mcqbio,mcqchem,mcqphy,mcqeng,maxmcq);                     
                     printf("\n The Minimum Theory marks you get between %.f, %.f, %.f and %.f is :: %.f \n",theorybio,theorychem,theoryphy,theoryeng,theorymin);
                     printf("\n The Minimum Mcq marks you get between %.f, %.f, %.f and %.f is :: %.f \n",mcqbio,mcqchem,mcqphy,mcqeng,minmcq);
                    printf("\n The Maximum Theory marks you get between %.f, %.f, %.f, %.f and %.f is :: %.f \n",bio,chem,phy,com,eng,max);
                    printf("\n The Maximum Theory marks you get between %.f, %.f, %.f, %.f and %.f is :: %.f \n",bio,chem,phy,com,eng,min);
                     printf("\n Total Marks is :: %.2f \n",allTotal);
                     
                     printf("\n Average Marks is :: %.2f \n",average);
                     
                     printf("\n Percentage is :: %.2f \n",percentage);


                     meritTotal = bio + chem + phy;
                     meritPer = ((meritTotal) * 100) / 300;

                     printf("Your merit total is :: '%.f' \n",meritTotal);
                     printf("Your merit Percentage is :: '%.f' \n",meritPer);
                    
                     if(percentage >= 90 ){
                               printf("\n  Grade 'A' \n");
                               printf("\n Congratulaions you are passed with Very Good Marks... :) \n");
                         }
                else if(percentage >= 80 ){
                               printf("\n  Grade 'B' \n");
                               printf("\n Congratulaions you are passed with Very Good Marks... :) \n");
                         }
                else if(percentage >= 70 ){
                               printf("\n  Grade 'C' \n");
                               printf("\n Congratulaions you are passed with average Marks... :|  \n");
          }                          
                else if(percentage >= 60 ){
                               printf("\n  Grade 'D' \n");
                               printf("\n Congratulaions you are passed with average Marks... :|  \n");               }
                              
                   else if(percentage >= 50 ){
                               printf("\n  Grade 'E' \n");
                               printf("\n Congratulaions you are passed... :) \n");
                               }    
                else if(percentage <= 37 ){
                               printf("\n  Grade 'F' \n");
                               printf("\n Sorry better luck next time you are failed... :( \n");
                               }
            }
            else{
              printf("Please Enter Valid Input For A group input 1");
              printf("Please Enter Valid Input For B group input 2");              

            }
            
                 
                           return 0;      
            
            }