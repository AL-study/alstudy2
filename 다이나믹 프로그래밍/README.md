# 다이나믹 프로그래밍

백준 온라인 저지에서 분류별 알고리즘 풀기-> 다이나믹 프로그래밍 문제를 푼다. DP는 많이 나오는 유형이므로 꾸준히 풀면서 연습한다.

DP문제를 접근할 때는 다음의 사항을 고려해야 한다.

1. DP를 어떻게 정의할 것인가?
   
   - 항상 N번째 DP배열에 정답이 저장되어 있는것은 아니다. 정답을 구하기 위해 원하는 값을 저장(메모이제이션)하는 배열이다. 따라서 먼저 DP배열에 어떤값을 저장해야 그 값을 이용해서 답을 구할 수 있는지를 생각해봐야 한다.
   
2. DP배열의 초기화

   - 최솟값을 구하고 싶은데 DP값을 전역변수로 선언만한다면 어떤 값을 출력해도 0을 출력할 것이다. 이런실수는 생각보다 흔하게 볼 수 있다. (~~그게바로 접니다.~~) DP는 처음 저장된 값에 따라 값을 메모이제이션하면서 연쇄적으로 값을 저장하는 배열이다. 따라서 처음 값의 설정을 제대로 해주어야 원하는 값이 나온다.

     

## 문제 List

- ### [BOJ 10844 쉬운 계단 수](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%2010844%20쉬운%20계단%20수.md)

- ### [BOJ 2163 초콜릿 자르기](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%202163%20초콜릿%20자르기.md)

- ### [BOJ 9461 파도반 수열](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%209461%20파도반%20수열.md)

- ### [BOJ 14501 퇴사 ★](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%2014501%20퇴사.md)

- ### [BOJ 1010 다리 놓기 ★★](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%201010%20다리%20놓기.md)

- ### [BOJ 9465 스티커](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%209465%20스티커.md)

- ### [BOJ 11057 오르막 수](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%2011057%20오르막%20수.md)

- ### [BOJ 2167 배열의 합](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%202167%20배열의%20합.md)

- ### [BOJ 2294 동전 2](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%202294%20동전%202.md)

- ### [BOJ 1699 제곱수의 합](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%201699%20제곱수의%20합.md)

- ### [BOJ  11048 이동하기](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%2011048%20이동하기.md)

- ### [BOJ  11055 가장 큰 증가 부분 수열](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%2011055%20가장%20큰%20증가%20부분%20수열.md)

- ### [BOJ  2133 타일채우기 ★](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%202133%20타일채우기.md)

- ### [BOJ  11722 가장 긴 감소하는 부분 수열 ★](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%2011722%20가장%20긴%20감소하는%20부분%20수열.md)

- ### [BOJ  11054 가장 긴 바이토닉 부분 수열 ★★](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%2011054%20가장%20긴%20바이토닉%20부분%20수열.md)

- ### [BOJ  2225 합분해](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%202225%20합분해.md)

- ### [BOJ  1309 동물원](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%201309%20동물원.md)

- ### [BOJ  1965 상자넣기](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%201965%20상자넣기.md)

- ### [BOJ  6359 만취한 상범](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%206359%20만취한%20상범.cpp)

- ### [BOJ  1937 욕심쟁이 판다★★](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%201937%20욕심쟁이%20판다.md)

- ### [BOJ  1915 가장 큰 정사각형 ★](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%201915%20가장%20큰%20정사각형.md)

- ### [BOJ  11066 파일 합치기 ★★](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%2011066%20파일%20합치기.md)

- ### [BOJ  2096 내려가기](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%202096%20내려가기.md)

- ### [BOJ  2011 암호코드 ★](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%202011%20암호코드.md)

- ### [BOJ  9507 Generations of Tribbles ](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%209507%20Generations%20of%20Tribbles.cpp)

- ### [BOJ  10164 격자상의 경로](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%2010164%20격자상의%20경로.md)

- ### [BOJ  2631 줄세우기](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%202631%20줄세우기.md)

- ### [BOJ  3943 헤일스톤 수열](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%203943%20헤일스톤%20수열.md)

- ### [BOJ  11049 행렬 곱셈 순서 ★](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%2011049%20행렬%20곱셈%20순서.md)

- ### [BOJ  5557 1학년](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%205557%201학년.md)

- ### [BOJ  1495 기타리스트](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%201495%20기타리스트.md)

- ### [BOJ  2302 극장좌석 ★](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%202302%20극장좌석.md)

- ### [BOJ  11060 점프 점프](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%2011060%20점프%20점프.md)

- ### [BOJ  9084 동전](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%209084%20동전.md)

- ### [BOJ  9251 LCS](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%209251%20LCS.cpp)

- ### [BOJ  2352 반도체 설계](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%202352%20반도체%20설계.cpp)

- ### [BOJ  8895 막대 배치](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%208895%20막대%20배치.md)

- ### [BOJ  2291 sequence](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%202291%20sequence.cpp)

- ### [BOJ  18235 지금 만나러 갑니다](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%2018235%20지금%20만나러%20갑니다.cpp)

- ### [BOJ  1507 궁금한 민호](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%201507%20궁금한%20민호.cpp)



