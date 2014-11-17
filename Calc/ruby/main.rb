# encoding: utf-8

require 'Qt'
require './CalcWidget.rb'

app = Qt::Application.new(ARGV)
widget = CalcWidget.new
widget.show

app.exec()
