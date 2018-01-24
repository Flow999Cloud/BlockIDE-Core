import lazyLoading from './lazyLoading'

export default {
  name: 'My Contracts',
  path: '/my-contracts',
  component: lazyLoading('my-contracts/MyContracts'),
  meta: {
    default: true,
    title: 'menu.myContracts',
    iconClass: 'vuestic-icon vuestic-icon-files'
  }
}
