//û���������������ĳ����� 
int game(int* guess, int guessSize, int* answer, int answerSize){
    int i,j,ans = 0;
    for(i=0;i<3;i++)
    {
        if(guess[i] == answer[i]) ans += 1;
    }
    return ans;
}
