# pcsx2-1.4.0-rr
pcsx2-1.4.0にTAS作成のための機能を追加した非公式エミュレータです。  
pcsx2-rr(<https://code.google.com/archive/p/pcsx2-rr/>)を参考にしています。
ただ、だいぶ中身が変わっており単純なマージはできなかったのでかなりソースコードは変わっています。  
  
# ダウンロード
windows10のみビルド後の実行ファイルを置いておきます。  
それ以外のOSは未確認です。一応公式で対応しているOSではビルドして使えるはずです。  
[pcsx2-1.4.0-rr](https://github.com/pocokhc/pcsx2-1.4.0-rr/releases)  
  
動作させるために以下が必要です。(公式から引用)  
You need the Visual C++ 2015 x86 Redistributable for this version to work.  
Download it [HERE](https://www.microsoft.com/en-us/download/details.aspx?id=48145)  
  

# 追加機能
* メニューバー
	* Movie

|ボタン|機能|
|---|---|
|Record|Recordモードでファイルを開きます。ファイルの中身は初期化されます。|
|Play|Replayモードでファイルを開きます。|
|Stop|ファイルを閉じます。ファイルクローズをするので終了したら呼んでください。|
※Record,PlayともにStop状態で始まります。Pキーを押して再生してください。
  
  
* ショートカットキー

|ボタン|機能|
|---|---|
|P|pause/unpauseの切り替え|
|space|frame advance|
|R|キームービーの再生モードから録画モードへの切り替え|

# キームービー作成想定手順
1. ゲームを始める前にRecord/Playを始めます。  
2. Boot CDVDからゲームを起動します。  
　※(full)と(fast)ですが、fastで起動したキーファイルはfast専用になりそう（未検証）  
　　同じ起動方法で起動する方がいいと思います。  
3. 停止していますので、Pキーで動かします。  
4. Playで始めた場合は再開した場所までいき、そこでRキーを押します。  
5. ゲーム中は以下の手順でTASを作っていきます。  

|ボタン|機能|
|---|---|
|P    |pause/unpause|
|space|frame advance|
|F1       |QS|
|F2       |toggle save slot(+1)|
|SHIFT+F2 |toggle save slot(-1)|
|F3       |QL|


# 録画想定手順
1. ゲームを始める前にPlayで始めます。
2. ゲームを始めたら止まっていると思いますので、F12キーで録画を開始します。  
※録画ファイルの保存場所は権限のある場所にしてください(windows10だとCドライブ以下は権限がないのでホームディレクトリ推奨)  
※権限がない等で保存されない場合でも警告等ありませんのでファイルができているか確認したほうがいいです。  
※音ファイルは別にpcsx2のexeファイルと同じディレクトリに「recorde.wav」で作成されます。  
※音ファイルと映像ファイルを同期させるために録画中はPauseやQL,QSはしない方がいい気がします。  
  

# ビルド方法(2017/1/6現在)(windows10)
  
用意するもの  
  
Visual Studio Comunnity 2015(<https://www.visualstudio.com/vs/community/>)  
※デフォルト設定だとC++が足りないので、カスタムインストールでC++関係も入れてください。  
DirectX Software Development Kit (June 2010)(<https://www.microsoft.com/en-us/download/details.aspx?id=6812>)  
※デフォルト設定のインストールでおｋです。  
  
あとは、ソースコード内の「PCSX2_suite.sln」が開けると思うので開いてビルドでいけるはずです。  
  

# ソースコードの変更箇所
元のコードから変更している箇所にはすべてコメントで  
//--TAS--//  
を入れてあります。これで検索かければわかると思います。  



# その他(使う側)
* キーファイルですが、pcsx2のp2mファイルとは互換性がありません。
* ゲーム画面だけフリーズした時  
メインメニューにフォーカスをあててからゲーム画面にフォーカスするとなおります。  
原因は分かりませんがEmu側でいろいろやってるタイミングに何かすると起こるっぽいです。  
  
* ゲーム画面だけフリーズした時2  
ゲーム起動中でpause中にコントローラの設定などメインフレームを動かすと固まる場合があります。  
その時はシステムのメニューから中断→再開とすると治ります。  
  
* pscx2事態がフリーズする  
滅多にないと思いますが、もしあったら再起動です…  
  
* スペース押しっぱなしで普通に再生できない？  
現状出来ないです。実現の仕方がよくわかっていません。  
  
* desyncは解決された？  
多分されたと信じたいです。  
キーファイルは完全に内部のframe単位で管理するようにしているので、Emu側でどれだけframe管理ができているか次第です。  
現在、実際にTAS作ってみて確認してます。  
  
* p2m2ファイル(キームービーファイル)がやたらサイズが大きい  
現状、サイズ度外視でキーの情報すべてを保存しています。  
解析して必要な情報だけにすればもう少し減りますが…  
その

# その他(作成側)
* Lua機能の追加に関して  
時間がかかりそうなので今のところ見送りです。  
参考になるものがあればいいのですが…  

* GUIに関して  
wxWidgetsというものを使っています。  
wxWidgetsの知識が全然ないのであまり作りこめていません。  
作れればキー情報を録画中に操作できるような機能とかいいかもしれませんね。  


------------------------
**Licence**  
公式のライセンス通りです。  
[License GNU LGPL](http://www.gnu.org/licenses/lgpl.html)  

