def solve():
    """
    1つのテストケースを解く関数
    """
    N = int(input())
    S = input()

    # 文字列がソート済みの場合 (s[i] > s[i+1] となる箇所がない)
    # この場合は、一番大きい末尾の文字を削除するのが最適
    if all(S[i] <= S[i+1] for i in range(N - 1)):
        print(S[:-1])
        return

    # s[i] > s[i+1] となる最初のiを見つける
    remove_idx = -1
    for i in range(N - 1):
        if S[i] > S[i+1]:
            remove_idx = i
            break
    
    # remove_idx の文字を削除した文字列を出力
    result = S[:remove_idx] + S[remove_idx+1:]
    print(result)


# --- メイン処理 ---
# T個のテストケースが与えられる
T = int(input())
for _ in range(T):
    solve()
