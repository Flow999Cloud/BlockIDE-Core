import lazyLoading from './lazyLoading'

export default {
  name: 'Transactions',
  path: '/transactions',
  component: lazyLoading('transactions/Transactions'),
  meta: {
    default: true,
    title: 'menu.transactions',
    iconClass: 'vuestic-icon vuestic-icon-forms'
  }
}
