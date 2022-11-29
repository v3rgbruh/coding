from django.urls import path
from base.views import order_views as views

urlpatterns = [
    path('', views.get_orders, name='orders'),
    path('myorders/', views.get_my_orders, name='orders-my'),
    path('add/', views.add_order_items, name='orders-add'),
    path('<str:pk>/deliver/', views.update_order_to_delivered, name='orders-deliver'),
    path('<str:pk>/pay/', views.update_order_to_paid, name='orders-pay'),
    path('<str:pk>/', views.get_order_by_id, name='orders-get'),
]
