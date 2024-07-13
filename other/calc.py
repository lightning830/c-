import sys
import tkinter as tk

def main():
    root = tk.Tk()
    root.title("電卓")
    den = Dentaku(root)
    den.format()
    root.mainloop()

class Dentaku():
    # 初期化
    def __init__(self, root) -> None:
        self.tf = tk.Frame(root)
        self.tf.grid(column=0, row=0, padx=15, pady=15)

        # ボタン配置，またその時実行する関数
        ButtonDef=(
            (4,0,"0", self.numinput),
            (3,0,"1", self.numinput),
            (3,1,"2", self.numinput),
            (3,2,"3", self.numinput),
            (2,0,"4", self.numinput),
            (2,1,"5", self.numinput),
            (2,2,"6", self.numinput),
            (1,0,"7", self.numinput),
            (1,1,"8", self.numinput),
            (1,2,"9", self.numinput),
            (4,1,"*", self.operation),
            (4,2,"/", self.operation),
            (1,3,"-", self.operation),
            (2,3,"+", self.operation),
            (3,3,"=", self.equal),
            (4,3,"C", self.clear),
            (5,0,".", self.period)
        )

        # ボタン設定，描画
        root.option_add('*Button.font', 'MSゴシック 28')
        for r, c, label, func, in ButtonDef:
            Button = tk.Button(self.tf, text=label)
            Button.bind("<Button-1>", func) #ボタンに関数を割り当て
            Button.grid(column=c, row=r, sticky=tk.N + tk.E + tk.S + tk.W)

        # 数値画面の設定，描画
        root.option_add('*Entry.font', 'MSゴシック 32')
        self.NumBox = tk.Entry(self.tf,  width=10, justify=tk.RIGHT)
        self.NumBox.insert(tk.END, '0')
        self.NumBox.grid(column=0, columnspan=4, row=0)

    # 数字が押されたとき
    def numinput(self, event):
        # n0に代入していく

        # ボタンの数字を記録
        n = int(event.widget['text'])

        if self.decimal == 1: # 整数のとき
            self.n0 = self.n0 * 10 + n
        else: # 少数点以下のとき
            self.n0 += self.decimal * n # decimalは小数点以下何桁なのかを表している
            self.decimal *= 0.1 # さらに小数点の位置を下げる
        self.input_flag = True #数字入力直後であることを記録
        self.update()

    # 演算子が押されたとき
    def operation(self, event):
        # 連続で演算子を入力した場合（数字入力直後ではない場合）は，演算子のみ更新する
        if self.input_flag == False:
            self.op = event.widget['text']
            return

        # 既に何か式が完成しているときは計算(例えば，2+3のあとに+を入力したときなど)
        if self.op:
            self.calc()

        # 入力された演算子の登録
        self.op = event.widget['text']

        #numinputでn0に上書きするため，n1に避難
        self.n1 = self.n0

        #numinputで上書きするために0に初期化しておく
        self.decimal = 1
        self.n0 = 0 
        self.input_flag = False

    # イコールが押されたとき
    def equal(self, event):
        if self.op:
            self.calc()
        self.op = ''
        # self.format()
    
    # クリアが押されたとき
    def clear(self, event):
        self.format()
        self.update()

    # ピリオドが押されたとき
    def period(self, event):
        self.decimal = 0.1 # 小数点1桁にする
    
    # 初期に戻す関数
    def format(self):
        self.n0 = self.n1 = 0
        self.op = '' # 演算子を空にする
        self.decimal = 1 # 整数にする

    # 表示更新関数
    def update(self):
        self.NumBox.delete(0, tk.END) # 今表示されている数字を削除
        self.NumBox.insert(tk.END, self.n0) # 現在のn0を入力
        # print(self.n0)

    # 計算
    def calc(self):
        if self.op == '+':
            self.n0 = self.n1 + self.n0
        elif self.op == '-':
            self.n0 = self.n1 - self.n0
        elif self.op == '*':
            self.n0 = self.n1 * self.n0
        elif self.op == '/':
            self.n0 = self.n1 / self.n0
        self.update()

if __name__ == '__main__':
    main()