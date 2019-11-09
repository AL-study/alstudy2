### 3090. 차이를 최소로 ★★

- 점수가 있는 서브 태스크문제로 인접한 수의 차이의 최댓값을 가장 작게 만든 배열을 출력해야함

- 배열을 아래에서 위로, 다시 위에서 아래로 총 2번의 순회를 통해 arr+mid값과 다음 또는 이전의 배열값과 비교하며 총 횟수인 T를 초과하는지의 유무로 low, high값을 갱신 (이런 접근방식을 전혀 생각하지 못했다...)

- ```c++
  #include <iostream>
  using namespace std;
  int arr[100005], BUF[100005];
  int n;
  int target;
  int go(int d)
  {
      for (int i = 0; i < n; ++i)
          BUF[i] = arr[i];
      int ans = 0;
      for (int i = 0; i < n - 1; ++i)
      {
          if (BUF[i + 1] > BUF[i] + d)
          {
              ans += BUF[i + 1] - (BUF[i] + d);
              BUF[i + 1] = BUF[i] + d;
          }
      }
      for (int i = n - 1; i > 0; --i)
      {
          if (BUF[i - 1] > BUF[i] + d)
          {
              ans += BUF[i - 1] - (BUF[i] + d);
              BUF[i - 1] = BUF[i] + d;
          }
      }
      if (ans <= target)
          return 1;
      else
          return 0;
  }
  int main(void)
  {	
  	int maxnum=0;
      for (int i = 0; i < 100005; i++)
          arr[i] = BUF[i] = 0;
      cin >> n >> target;
      for (int i = 0; i < n; ++i){
      	cin >> arr[i];
      	maxnum=max(maxnum,arr[i]);
  	}
          
      int low = 0, high = maxnum;
      int mid = (low + high) / 2;
      while (low < high){
          mid = (low + high) / 2;
          //target 안에 수정가능함
          if (go(mid))
              high = mid;
          //target 내에 수정불가능
          else
              low = mid + 1;
      }
      for (int i = 0; i<n; i++)
          cout << arr[i] << " ";
      cout << endl;
      return 0;
  }
  ```

- #### 참고 출처 : [섭 님의 블로그](http://blog.naver.com/PostView.nhn?blogId=zmfldlwl&logNo=221044141645&parentCategoryNo=&categoryNo=56&viewDate=&isShowPopularPosts=true&from=search)

