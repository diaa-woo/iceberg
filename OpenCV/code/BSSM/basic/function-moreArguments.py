# *arguments: 가변 인자(Variable Argument): 별 한개면 리스트
# **keywords: 키워드 인자(Keyword arguments): 별 두개면 딕셔너리
def caffe(beverage, *arguments, **keywords) :
    print("Do U have any", beverage, "?")
    for arg in arguments:
        print(arg)
    print("*****")
    for kw in keywords:
        print(kw, ':', keywords[kw])

caffe("coffee", "it's yummy, sir.", "Would you try?",
      barista = "Jay Kim",
      client = "BSSM",
      cup = "Venti-size")