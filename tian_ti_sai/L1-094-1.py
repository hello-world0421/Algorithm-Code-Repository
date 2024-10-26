class TextEditor:
    def __init__(self, text):
        self.text = text
        self.clipboard = ''

    def cut(self, start, end):
        self.clipboard = self.text[start - 1:end]
        self.text = self.text[:start - 1] + self.text[end:]

    def paste(self, before, after):
        index = self.text.find(before) + len(before)
        if index == -1:
            index = len(self.text)
        self.text = self.text[:index] + self.clipboard + after + self.text[index:]

# 测试代码
s = "The quick brown fox jumps over the lazy dog"
editor = TextEditor(s)
editor.cut(4, 9)
editor.paste("quick ", " fox")
print(editor.text)  # Output: 'The brown fox jumps over the lazy dog'
